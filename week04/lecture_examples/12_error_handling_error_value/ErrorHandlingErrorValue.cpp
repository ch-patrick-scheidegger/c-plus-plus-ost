
#include <ios>
#include <iostream>
#include <string>

auto contains(std::string const & s, int number) -> bool {
  auto substring = std::to_string(number);
  return s.find(substring) != std::string::npos;
}


auto main() -> int {
  std::cout << std::boolalpha << contains("The answer is 42!", 42);
}
