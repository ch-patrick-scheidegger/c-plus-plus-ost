#include <iostream>


auto check(int i) -> void {
  if (i % 2) {
    throw "is even";
  }
  throw 0;
}

auto printIsEven(int i) -> void try {
  check(i);
} catch(int) {
  std::cout << "that's odd";  
} catch(...) {
  std::cout << "very even";
}

auto main() -> int {
  printIsEven(1);
}