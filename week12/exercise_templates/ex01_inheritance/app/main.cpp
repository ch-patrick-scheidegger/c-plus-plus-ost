#include "inheritance.hpp"

auto main() -> int {
  std::cout << "a ------\n";
  forum_troll ft{};
  troll t{ft};
  monster &m{ft};
  std::cout << "b ------\n";
  ft.attack();
  t.attack();
  m.attack();
  std::cout << "c ------\n";
  ft.swing_club();
  t.swing_club();
  std::cout << "d ------\n";
  ft.health();
  t.health();
  m.health();
  std::cout << "end ------\n";
}