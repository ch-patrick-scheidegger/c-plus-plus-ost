#include <iostream>

struct Base {
  void sayHello() const {
    std::cout << "Hi, I'm Base\n";
  }
};

struct Derived : Base {
  void sayHello() const {
    std::cout << "Hi, I'm Derived\n";
  }
};
void greet(Base const & base) {
  base.sayHello();
}

int main() {
  Derived derived{};
  greet(derived);
}