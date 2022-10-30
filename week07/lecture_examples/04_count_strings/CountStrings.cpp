#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <ranges>
#include <string>


auto countStrings(std::istream & in, std::ostream & out) -> void {
  std::map<std::string, size_t> occurrences{};
  std::ranges::for_each(std::ranges::istream_view<std::string>(in), [&occurrences](auto const & str) {
	  ++occurrences[str];
  });
  for(auto const & occurrence : occurrences) {
    out << occurrence.first << " = " << occurrence.second << '\n';
  }
}

auto main() -> int {
	countStrings(std::cin, std::cout);
}
