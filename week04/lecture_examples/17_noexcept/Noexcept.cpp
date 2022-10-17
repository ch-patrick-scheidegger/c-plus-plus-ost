#include <iostream>


auto fail() -> void {
  throw 1;
}

auto lie() noexcept -> void  {
  fail();
}


auto main() -> int {
  try {
    lie();
  } catch(...) {
    std::cout << "That is unexpected!";
  }
}