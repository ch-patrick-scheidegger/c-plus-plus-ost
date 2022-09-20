#include <iostream>

auto main() -> int {
  size_t count{0};
  char c{};
  while (std::cin >> c) {
    ++count;
  }
  std::cout << count << "\n";
}
