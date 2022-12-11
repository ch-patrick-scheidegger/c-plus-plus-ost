#include <iostream>

struct Base {
  virtual auto sayHello() const -> void {
    std::cout << "Hi, I'm Base\n";
  }
};

struct Derived : Base {
  auto sayHello() const -> void{
    std::cout << "Hi, I'm Derived\n";
  }
};

auto greet(Base const & base) -> void {
  base.sayHello();
}

auto main() -> int {
  Derived derived{};
  greet(derived);
}
