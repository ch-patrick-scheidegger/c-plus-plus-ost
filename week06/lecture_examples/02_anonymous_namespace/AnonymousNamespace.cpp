#include <iostream>

namespace {   // anonymous
auto doit() -> void { // can not be called
              // outside this file
  std::cout << "doit called\n";
}
} // namespace

auto print() -> void { // callablefrom other
               // parts if declared
  doit();
  std::cout << "print called\n";
}

