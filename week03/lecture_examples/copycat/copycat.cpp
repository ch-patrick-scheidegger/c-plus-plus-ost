#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <ranges>

auto copycat_algorithm(std::ostream & outStream, std::istream & inStream) -> void {
  using input = std::istreambuf_iterator<char>;
  input eofIterator{};
  input inIterator{inStream};
  std::ostream_iterator<char> outIterator{outStream};
  std::copy(inIterator, eofIterator, outIterator);
}

auto copycat_ranges(std::ostream & outStream, std::istream & inStream) -> void {
  inStream >> std::noskipws;
  std::ostream_iterator<char> outIterator{outStream};
  std::ranges::istream_view<char> inputRange{inStream};
  std::ranges::copy(inputRange, outIterator);
}

auto main() -> int {
  // copycat_algorithm(std::cout, std::cin);
  copycat_ranges(std::cout, std::cin);
}
