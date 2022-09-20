#include <iostream>
#include <limits>
#include <sstream>

auto inputAge(std::istream &in) -> int {
  while (in.good()) {
    int age{-1};
    if (in >> age)
      return age;
    in.clear();  // remove fail flag
    in.ignore(); // ignore invalid character
    // in.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // whole
    // line
  }
  return -1;
}

auto main() -> int {
  std::cout << "Enter your age (invalid ignored): " << std::flush;
  auto age = inputAge(std::cin);
  std::cout << "\nYou are " << age << " years old\n";
}
