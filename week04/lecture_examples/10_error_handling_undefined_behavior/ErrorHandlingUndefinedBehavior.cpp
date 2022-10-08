
#include <iostream>
#include <vector>


auto main() -> int {
  std::vector v{1, 2, 3, 4, 5};
  std::cout << v[5] << '\n';
  v[5] = 7;
  std::cout << v[5] << '\n';
}

