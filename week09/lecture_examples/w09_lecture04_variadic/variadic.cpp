#include <iostream>
#include <string>

auto printAll(std::ostream & out) -> void {
}

template<typename First, typename...Types>
auto printAll(std::ostream & out, First const & first, Types const &...rest) -> void {
  out << first;
  if (sizeof...(Types)) {
    out << ", ";
  }
  printAll(out, rest...);
}

auto main() -> int {
  int i{42}; double d{1.25}; std::string book{"Lucid C++"};
  printAll(std::cout, i, d, book);
}
