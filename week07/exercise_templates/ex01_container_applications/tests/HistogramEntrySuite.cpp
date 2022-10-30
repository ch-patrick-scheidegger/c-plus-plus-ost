#include "HistogramEntrySuite.hpp"
#include "Statistics.hpp"
#include "Word.hpp"

#include <cute/cute.h>
#include <iterator>
#include <set>
#include <sstream>
#include <vector>

// using statistics::HistogramEntry;
// using text::Word;

TEST(testSameHistogramEntryIsEqual) {
  // HistogramEntry entry{Word{"Mouse"}, 15};
  // ASSERT_EQUAL(entry, entry);
}

TEST(testEqualHistogramEntriesAreEqual) {
  // HistogramEntry entry1{Word{"Train"}, 15};
  // HistogramEntry entry2{Word{"Train"}, 15};
  // ASSERT_EQUAL(entry1, entry2);
}

TEST(testDifferentWordIsNotEqual) {
  // HistogramEntry entry1{Word{"Screen"}, 1};
  // HistogramEntry entry2{Word{"Sun"}, 1};
  // ASSERT_NOT_EQUAL_TO(entry1, entry2);
}

TEST(testDifferentOccurrenceIsNnotEqual) {
  // HistogramEntry entry1{Word{"Grass"}, 4};
  // HistogramEntry entry2{Word{"Grass"}, 3};
  // ASSERT_NOT_EQUAL_TO(entry1, entry2);
}

TEST(testSortingOfHistogramEntries) {
  // std::vector<HistogramEntry> expected{
  //     {Word{"Year"}, 15},   {Word{"Day"}, 4},   {Word{"Month"}, 4},
  //     {Word{"Century"}, 1}, {Word{"Epoch"}, 0},
  // };
  // std::set<HistogramEntry> entries{cbegin(expected), cend(expected)};

  // ASSERT_EQUAL_RANGES(cbegin(expected), cend(expected), cbegin(entries),
  //                     cend(entries));
}

TEST(testLessThanByOccurrence) {
  // HistogramEntry entry1{Word{"Bottle"}, 9};
  // HistogramEntry entry2{Word{"Bottle"}, 8};
  // ASSERT_LESS(entry1, entry2);
}

TEST(testLessThanByWord) {
  // HistogramEntry entry1{Word{"Car"}, 7};
  // HistogramEntry entry2{Word{"Truck"}, 7};
  // ASSERT_LESS(entry1, entry2);
}

TEST(testLessThanOrEqual) {
  // HistogramEntry entry1{Word{"Tape"}, 9};
  // HistogramEntry entry2{Word{"CD"}, 5};
  // ASSERT_LESS_EQUAL(entry1, entry2);
}

TEST(testGreaterThan) {
  // HistogramEntry entry1{Word{"Knife"}, 7};
  // HistogramEntry entry2{Word{"Fork"}, 7};
  // ASSERT_GREATER(entry1, entry2);
}

TEST(testGreaterEqual) {
  // HistogramEntry entry1{Word{"Table"}, 0};
  // HistogramEntry entry2{Word{"Chair"}, 100};
  // ASSERT_GREATER_EQUAL(entry1, entry2);
}

TEST(testOutputOperator) {
  // std::ostringstream out{};
  // HistogramEntry entry{Word{"Lamp"}, 42};
  // out << entry;
  // ASSERT_EQUAL("Lamp: 42", out.str());
}

auto createHistogramEntrySuite() -> cute::suite {
  return cute::suite{"Histogram Entry Suite",
                     {
                         testSameHistogramEntryIsEqual,
                         testEqualHistogramEntriesAreEqual,
                         testDifferentWordIsNotEqual,
                         testDifferentOccurrenceIsNnotEqual,
                         testSortingOfHistogramEntries,
                         testLessThanByOccurrence,
                         testLessThanByWord,
                         testLessThanOrEqual,
                         testGreaterThan,
                         testGreaterEqual,
                         testOutputOperator,
                     }};
}
