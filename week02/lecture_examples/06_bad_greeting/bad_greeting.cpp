#include <iostream>
#include <string>

auto askForName(std::ostream &out) -> void {
  out << "Enter two names, please... ";
}

auto inputName(std::istream &in) -> std::string {
  std::string name{};
  in >> name;
  return name;
}

auto sayGreeting(std::ostream &out, std::string name1, std::string name2) -> void {
  out << "Hello " << name1 << ", do you love " << name2 << "?\n";
}

auto main() -> int {
  askForName(std::cout);
  sayGreeting(std::cout, inputName(std::cin),
              inputName(std::cin)); // order is unspecified
}
