#include <iostream>

auto factorial(int n) -> int {
  if (n > 1) {
    return n * factorial(n - 1);
  }
  return 1;
}

auto factorial(double n) -> double {
  double result = 1;
  if (n < 15) {
    return factorial(static_cast<int>(n));
  }
  while (n > 1) {
    result *= n;
    --n;
  }
  return result;
}

auto main() -> int {  
  std::cout << factorial(3) << '\n';
  std::cout << factorial(1e2) << '\n';
  
  // std::cout << factorial(10u) << '\n';
  // std::cout << factorial(1e1L) << '\n';
}
