#include <algorithm>

#include <iostream>
#include <iterator>
#include <map>

auto countVowels(std::istream& in, std::ostream& out) -> void {
  std::map<char, size_t> vowels{{'a', 0}, {'e', 0}, {'i', 0},
                                {'o', 0}, {'u', 0}, {'y', 0}};
  char c{};
  while (in >> c) {
    if (vowels.contains(c)) {  // only count those chars that are already in the map
      ++vowels[c];
      std::ranges::for_each(vowels, [&out](auto const& entry) {
        // entry is a pair<char, size_t>
        out << entry.first << " = " << entry.second << '\n';
      });
    }
  }
}

auto main() -> int {
  countVowels(std::cin, std::cout);
}
