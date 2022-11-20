#include <iostream>

template <typename T>
auto min(T const & left, T const & right) -> T const & {
  return left < right ? left : right;
}

auto main() -> int {
  std::cout << min("Java", "Rust");
}
