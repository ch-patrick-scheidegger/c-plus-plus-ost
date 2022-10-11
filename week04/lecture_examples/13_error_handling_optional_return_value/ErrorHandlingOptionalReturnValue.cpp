

#include <iostream>
#include <istream>
#include <optional>
#include <string>


auto inputName(std::istream & in) -> std::optional<std::string> {
  std::string name{};
  if (in >> name) return name;
  return {};
}

auto main() -> int {
  std::optional name = inputName(std::cin);
  if (name.has_value()) {
    std::cout << "Name: " << name.value() << '\n';
  }
}
