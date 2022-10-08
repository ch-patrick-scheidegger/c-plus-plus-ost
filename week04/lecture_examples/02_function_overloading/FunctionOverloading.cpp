#include <iostream>
#include <source_location>

auto incr(int & var) -> void {
  std::cout << std::source_location::current().function_name() << " overload called\n";
  var++;
}

auto incr(int & var, unsigned delta) -> void {
  std::cout << std::source_location::current().function_name() << " overload called\n";
  var += delta;
}

auto main() -> int {
  int value = 0;
  incr(value);
  incr(value, 5);
}


// auto incr(int & var) -> int { // Overloads solely based on the return type are not possible
//   std::cout << std::source_location::current().function_name() << " overload called\n";
//   return ++var;
// }