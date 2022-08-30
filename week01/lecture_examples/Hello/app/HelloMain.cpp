#include "HelloStruct.hpp"

#include <iostream>

auto main() -> int {
  Hello h{};
  h.sayHello(std::cout);
}
