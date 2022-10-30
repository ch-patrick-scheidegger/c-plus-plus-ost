#include <iostream>
#include <string>
#include <unordered_map>

auto main() -> int {
  std::unordered_map<std::string, int> words{};
  std::string s{};
  while (std::cin >> s) {
    ++words[s];
  }
  for (auto const& p : words) {
    std::cout << p.first << " = " << p.second << '\n';
  }
}
