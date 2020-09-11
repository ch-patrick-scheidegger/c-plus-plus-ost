#include "Point.h"
#include "Square.h"
#include <iostream>

int main() {
  Point point{1, 2};
  Point other = modify(point);
  std::cout << '{' << point.x << '/' << point.y << "}\n";
  std::cout << '{' << other.x << '/' << other.y << "}\n";

  Square s{Point{1, 2}, Point{9, 9}};
}
