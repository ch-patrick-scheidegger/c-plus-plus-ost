#include "ADL.hpp"

auto main() -> int {
  one::type_one t1{};
  f(t1);
  two::type_two t2{};
  f(t2);
  // h(t1);
  two::g(t1);
  // g(t1);
  g(t2);
}
