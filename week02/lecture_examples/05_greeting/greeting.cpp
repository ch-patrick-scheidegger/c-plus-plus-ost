#include <iostream>
#include <string>

auto askForName(std::ostream &out) -> void {
  out << "What is your name? ";
}

auto inputName(std::istream &in) -> std::string {
  std::string name{};
  in >> name;
  return name;
}

auto sayGreeting(std::ostream &out, std::string name) -> void {
  out << "Hello " << name << ", how are you?\n";
}

auto main() -> int {
  askForName(std::cout);
  sayGreeting(std::cout, inputName(std::cin));
}
