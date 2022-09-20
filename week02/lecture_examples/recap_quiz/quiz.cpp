#include "point.hpp"
#include "square.hpp"

#include <iostream>

auto main() -> int {
  Point point{1, 2};
  Point other = modify(point);
  std::cout << '{' << point.x << '/' << point.y << "}\n";
  std::cout << '{' << other.x << '/' << other.y << "}\n";

  Square s{Point{1, 2}, Point{9, 9}};
}
