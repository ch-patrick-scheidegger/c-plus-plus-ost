#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

auto sortedStringList(std::istream& in, std::ostream& out) -> void {
  using inIter = std::istream_iterator<std::string>;
  using outIter = std::ostream_iterator<std::string>;
  std::multiset<std::string> words{inIter{in}, inIter{}};
  std::ranges::copy(words, outIter(out, "\n"));
  auto current = cbegin(words);
  while (current != cend(words)) {
    auto endOfRange = words.upper_bound(*current);
    copy(current, endOfRange, outIter{out, ", "});
    out << '\n';  // next range on new line
    current = endOfRange;
  }
}

auto main() -> int {
  sortedStringList(std::cin, std::cout);
}
