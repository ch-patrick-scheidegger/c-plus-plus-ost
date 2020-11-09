#include "min.h"
#include <iostream>

int main() {
  int first;
  int second;
  if (std::cin >> first >> second) {
    auto const smaller = min(first, second);
    std::cout << "Smaller of " << first
              << " and " << second
              << " is: " << smaller << '\n';
  }
}
