#include <iostream>
#include <memory>
#include <utility>

auto create(int i) -> std::unique_ptr<int> {
  return std::make_unique<int>(i);
}

auto main() -> int {
  std::cout << std::boolalpha;

  auto pi = create(42);
  std::cout << "*pi = " << *pi << '\n';
  std::cout << "pi.valid? " << static_cast<bool>(pi) << '\n';
  
  auto pj = std::move(pi);
  std::cout << "*pj = " << *pj << '\n';
  std::cout << "pi.valid? " << static_cast<bool>(pi) << '\n';
}
