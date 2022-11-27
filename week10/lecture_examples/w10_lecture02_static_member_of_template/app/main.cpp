#include "static_member.hpp"
#include <iostream>

auto setDummyTo42() -> int {
  using dummytype = StaticMember<int>;
  dummytype::member = 42;
  return dummytype::member;
}

auto main() -> int {
  std::cout << StaticMember<double>::member << '\n';
  std::cout << StaticMember<int>::member << '\n';
  std::cout << setDummyTo42() << '\n';
  std::cout << StaticMember<int>::member << '\n';
}
