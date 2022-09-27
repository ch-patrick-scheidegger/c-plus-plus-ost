#include "Counting.hpp"

#include <algorithm>
#include <ios>
#include <istream>
#include <iterator>
#include <ranges>
#include <string>

auto charc(std::istream &input) -> unsigned {
  // std::istream_iterator<char> eofIterator{};
  // return distance(std::istream_iterator<char>{input}, eofIterator);
  return std::ranges::distance(std::ranges::istream_view<char>{input});
}

auto allcharc(std::istream &input) -> unsigned {
  input >> std::noskipws;
  return charc(input);
}

auto wc(std::istream &input) -> unsigned {
  // std::istream_iterator<std::string> eofIterator{};
  // return distance(std::istream_iterator<std::string>{input}, eofIterator);
  return std::ranges::distance(std::ranges::istream_view<std::string>{input});
}

auto lc(std::istream &input) -> unsigned {
  std::istreambuf_iterator<char> eof{};
  return std::count(std::istreambuf_iterator<char>{input}, eof, '\n');
  
  // input >> std::noskipws;
  // return std::ranges::count(std::ranges::istream_view<char>{input}, '\n');
}