#include <iostream>

template <typename F, typename...T>
auto min(F const & first, T const &...rest) -> F {
  auto const & restMin = min(rest...);
  return first < restMin ? first : restMin;
}

auto main() -> int {
  std::cout << min(3, 1, 4, 1, 5);
}
