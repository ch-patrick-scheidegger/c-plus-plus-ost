#include <iostream>
#include <string>

template <typename T>
auto _min(T const & left, T const & right) -> T const & {
  return left < right ? left : right;
}

auto main() -> int {
  using namespace std::string_literals;
  std::string const & smaller = _min("a"s, "b"s);
  std::cout << "smaller is: " << smaller;
}
