#include <cctype>
#include <iostream>

auto main() -> int {
  char c{};
  while (std::cin.get(c)) {
    std::cout.put(std::tolower(c));
  }
}
