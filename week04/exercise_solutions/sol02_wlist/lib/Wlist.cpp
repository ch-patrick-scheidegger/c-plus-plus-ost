#include "Wlist.hpp"
#include <algorithm>
#include <cctype>
#include <istream>
#include <iterator>
#include <set>
#include <string>

auto wlist(std::istream &input, std::ostream &output) -> void {
  std::istream_iterator<std::string> inIterator{input};
  std::istream_iterator<std::string> eof{};
  std::set words(inIterator, eof);
  std::ranges::copy(words, std::ostream_iterator<std::string>{output, "\n"});
}

auto caselessLess(std::string const &left, std::string const &right) -> bool {
  return lexicographical_compare(
      begin(left), end(left), begin(right), end(right),
      [](char leftChar, char rightChar) { return std::tolower(leftChar) < std::tolower(rightChar); });
};

auto wlist_caseless(std::istream &input, std::ostream &output) -> void {
  std::istream_iterator<std::string> inIterator{input};
  std::istream_iterator<std::string> eof{};
  std::set words(inIterator, eof, caselessLess);
  std::ranges::copy(words, std::ostream_iterator<std::string>{output, "\n"});
}