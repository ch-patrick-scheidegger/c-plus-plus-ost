#include <iostream>


void fail() {
  throw 1;
}

void lie() noexcept {
  fail();
}


auto main() -> int {
  try {
    lie();
  } catch(...) {
    std::cout << "That is unexpected!";
  }
}