
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

auto inputNameWithDefault(std::istream& in,
                          std::string const& def = "anonymous") -> std::string {
  std::string name{};
  in >> name;
  return name.size() ? name : def;
}

auto main() -> int {
  std::istringstream input{};
  auto name = inputNameWithDefault(input);
  std::cout << name;
}
