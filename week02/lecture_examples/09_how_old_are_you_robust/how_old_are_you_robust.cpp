#include <iostream>
#include <sstream>

auto inputAge(std::istream &in) -> int {
  while (in) {
    std::string line{};
    getline(in, line);
    int age{-1};
    // /*
    std::istringstream is{line};
    if (is >> age)
      return age;
    // */
    // alternative:
    /*
    try{
		age = std::stoi(line);
		return age;
    }
    catch(...){}
    */
  }
  return -1;
}

auto main() -> int {
  std::cout << "Enter your age: " << std::flush;
  auto age = inputAge(std::cin);
  std::cout << "\nYou are " << age << " years old\n";
}
