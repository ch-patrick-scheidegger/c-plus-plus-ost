#include <iostream>

auto incr(int & var, unsigned delta = 1) -> void;

//The function definition could be placed in a different source file
auto incr(int & var, unsigned delta) -> void {
  var += delta;
}

auto main() -> int {
  int counter{0};
  incr(counter);    //uses default for delta
  incr(counter, 5);
}
