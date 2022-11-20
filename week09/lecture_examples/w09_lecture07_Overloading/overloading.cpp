#include <iostream>

template <typename T>
auto min(T left, T right) -> T {
  return left < right ? left : right;
}


auto main() -> int {
  std::cout << min("Gregor Clegane", "Tyrion Lannister");
}
