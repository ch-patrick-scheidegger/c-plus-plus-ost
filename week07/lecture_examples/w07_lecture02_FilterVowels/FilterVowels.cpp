#include <set>
#include <iostream>

void filterVowels(std::istream & in, std::ostream & out) {
  std::set const vowels{'a', 'e', 'o', 'u', 'i', 'y'};
  char c{};
  while (in >> c) {
    if (!vowels.count(c)) {
      out << c;
    }
  }
}
int main() {
  filterVowels(std::cin, std::cout);
}
