#include "staticMember.hpp"
#include <iostream>

auto setMemberTo42() -> int;

auto main() -> int {
  std::cout << StaticMember<double>::member << '\n';
  std::cout << StaticMember<int>::member << '\n';
  std::cout << setMemberTo42() << '\n';
  std::cout << StaticMember<int>::member << '\n';
}
