#include "WordHistogramSuite.hpp"
#include "Statistics.hpp"
#include "Word.hpp"

#include <cute/cute.h>

#include <algorithm>
#include <istream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>


namespace text {

inline namespace {

 auto operator<<(std::ostream& out, std::map<text::Word, int> const& occurrences)
     -> std::ostream& {
   out << "{\n";
   std::ranges::transform(occurrences,
                          std::ostream_iterator<std::string>{out, "\n"},
                          [](auto const& occurrence) {
                            std::ostringstream result{};
                            result << "\t{\"" << occurrence.first
                                   << "\": " << occurrence.second << "},";
                            return result.str();
                          });
   out << "}\n";
   return out;
 }

}  // namespace

}  // namespace text

TEST(testHistogramEmptyInput) {
   std::istringstream input{};
   auto const result = statistics::histogram(input);
   ASSERTM("Result is expected to be empty for empty input.", result.empty());
}

TEST(testHistogramWithSingleWord) {
   std::map<text::Word, int> expected{{text::Word{"Wuuzaa"}, 1}};
   std::istringstream input{"Wuuzaa"};
   auto const result = statistics::histogram(input);
   ASSERT_EQUAL(expected, result);
}

TEST(testHistogramWithSameWordInDifferentCasings) {
   std::map<text::Word, int> expected{{text::Word{"Wuuzaa"}, 4}};
   std::istringstream input{"Wuuzaa wuuzaa wUUzAA WUUZAA"};
   auto const result = statistics::histogram(input);
   ASSERT_EQUAL(expected, result);
}

TEST(testHistogramOfMutlipleWords) {
   std::map<text::Word, int> expected{
       {text::Word{"all"}, 2},    {text::Word{"and"}, 1},
       {text::Word{"bind"}, 1},   {text::Word{"bring"}, 1},
       {text::Word{"Dark"}, 2},   {text::Word{"darkness"}, 1},
       {text::Word{"die"}, 1},    {text::Word{"doomed"}, 1},
       {text::Word{"Dwarf"}, 1},  {text::Word{"Elven"}, 1},
       {text::Word{"find"}, 1},   {text::Word{"for"}, 4},
       {text::Word{"halls"}, 1},  {text::Word{"his"}, 1},
       {text::Word{"in"}, 4},     {text::Word{"kings"}, 1},
       {text::Word{"Land"}, 2},   {text::Word{"lie"}, 2},
       {text::Word{"Lord"}, 1},   {text::Word{"lords"}, 1},
       {text::Word{"Men"}, 1},    {text::Word{"Mordor"}, 2},
       {text::Word{"Mortal"}, 1}, {text::Word{"Nine"}, 1},
       {text::Word{"of"}, 3},     {text::Word{"on"}, 1},
       {text::Word{"One"}, 4},    {text::Word{"Ring"}, 3},
       {text::Word{"Rings"}, 1},  {text::Word{"rule"}, 1},
       {text::Word{"Seven"}, 1},  {text::Word{"Shadows"}, 2},
       {text::Word{"sky"}, 1},    {text::Word{"stone"}, 1},
       {text::Word{"the"}, 9},    {text::Word{"their"}, 1},
       {text::Word{"them"}, 4},   {text::Word{"Three"}, 1},
       {text::Word{"throne"}, 1}, {text::Word{"to"}, 4},
       {text::Word{"under"}, 1},  {text::Word{"where"}, 2}};
   // Test-Input from: https://lotr.fandom.com/de/wiki/Ringgedicht
   std::istringstream input{
       "Three Rings for the Elven-kings under the sky,\n"
       "Seven for the Dwarf-lords in their halls of stone,,\n"
       "Nine for Mortal Men doomed to die,,\n"
       "One for the Dark Lord on his dark throne,\n"
       "In the Land of Mordor where the Shadows lie.,\n"
       "One Ring to rule them all, One Ring to find them,,\n"
       "One Ring to bring them all and in the darkness bind them,\n"
       "In the Land of Mordor where the Shadows lie."};
   auto const result = statistics::histogram(input);
   ASSERT_EQUAL(expected, result);
}

TEST(testHistogramWithFlySentence) {
   std::map<text::Word, int> expected{{text::Word{"Fliegen"}, 6},
                                      {text::Word{"hinter"}, 1},
                                      {text::Word{"nach"}, 1},
                                      {text::Word{"Wenn"}, 1}};
   std::istringstream input{
       "Wenn hinter Fliegen Fliegen fliegen, fliegen Fliegen Fliegen nach."};
   auto const result = statistics::histogram(input);
   ASSERT_EQUAL(expected, result);
}

auto createWordHistogramSuite() -> cute::suite {
  return cute::suite{"Word Histogram Suite",
                     {
                         testHistogramEmptyInput,
                         testHistogramWithSingleWord,
                         testHistogramWithSameWordInDifferentCasings,
                         testHistogramOfMutlipleWords,
                         testHistogramWithFlySentence,
                     }};
}
