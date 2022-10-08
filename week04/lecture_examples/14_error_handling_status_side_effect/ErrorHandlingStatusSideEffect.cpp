

#include <iostream>
#include <string>


auto main() -> int {
  std::string name{};
  std::cin >> name;
  if (std::cin.fail()) { //Member variable
    //Handle error case
  }
}
