#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>

auto cat_algorithm(std::ostream& outStream, std::istream& inStream) -> void {
  using input = std::istream_iterator<std::string>;
  input inIterator{inStream};
  input eofIterator{};
  std::ostream_iterator<std::string> outIterator{outStream, " "};
  std::copy(inIterator, eofIterator, outIterator);
}

auto cat_ranges(std::ostream& outStream, std::istream& inStream) -> void {
  std::ostream_iterator<std::string> outIterator{outStream, " "};
  std::ranges::istream_view<std::string> inputRange{inStream};
  std::ranges::copy(inputRange, outIterator);
}

auto main() -> int {
  // cat_algorithm(std::cout, std::cin);
  cat_ranges(std::cout, std::cin);
}
