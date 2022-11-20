#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

template <typename T>
auto min(T & left, T & right) -> T {
  return left < right ? left : right;
}

auto min(std::string const & left, std::string const & right) -> std::string {
  return lexicographical_compare(begin(left), end(left),
          begin(right), end(right),
          [](char l, char r) {
    return tolower(l) < tolower(r);
  }) ? left : right;
}

auto main() -> int {
  std::string small{"aa"};
  std::string const capital{"ZZ"};
  std::cout << min(small, capital) << '\n'; //ZZ
}
