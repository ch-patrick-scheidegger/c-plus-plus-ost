#include <iostream>
#include <string>

template <typename T>
auto _min(T const & left, T const & right) -> T const & {
  return left < right ? left : right;
}

auto main() -> int {
  std::string java{"Java"};
  std::string const rust{"Rust"};
  std::cout << _min(java, rust);
}
