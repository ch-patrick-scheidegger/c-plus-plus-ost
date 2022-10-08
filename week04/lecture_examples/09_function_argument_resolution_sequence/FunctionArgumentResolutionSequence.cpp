
#include <iostream>
#include <string>

auto askForName(std::ostream & out) -> void {
  out << "Tell me two names:\n";
}

auto inputName(std::istream & input) -> std::string {
  std::string name{};
  input >> name;
  return name;
}

auto sayGreeting(std::ostream & out,
                 std::string name1,
                 std::string name2) -> void{
  out << "Hello " << name1 << ", do you love " << name2 << "?\n";
}

auto main() -> int {
  askForName(std::cout);
  sayGreeting(std::cout,
              inputName(std::cin),
              inputName(std::cin));
}
