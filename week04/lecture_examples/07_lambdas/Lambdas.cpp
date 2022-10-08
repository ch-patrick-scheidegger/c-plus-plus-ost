


#include <cctype>
#include <iostream>


struct S {
  auto foo() -> void {
    auto square = [this] {
      member *= 2;
    };
  }
private:
  int member{};
};


auto main() -> int {
  auto const g = [](char c) -> char {
    return std::toupper(c);
  };
  g('a');

  int x = 5;
  auto l1 = [x]() mutable {
    std::cout << ++x << '\n';
  };
  l1();

  auto const l2 = [&x]() {
    std::cout << ++x << '\n';
  };
  l2();

  auto l3 = [=]() mutable {
    std::cout << ++x << '\n';
  };
  l3();

  auto const l4 = [&]() {
    std::cout << ++x << '\n';
  };
  l4();

  auto squares = [x = 1]() mutable {
    std::cout << (x *= 2) << '\n';
  };
}
