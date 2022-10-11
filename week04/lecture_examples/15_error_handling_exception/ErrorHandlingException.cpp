

#include <iostream>
#include <stdexcept>
#include <string>

auto sayGreeting(std::ostream & out, std::string name) -> void {
  if (name.empty()) {
    throw std::invalid_argument{"Empty name"};
  }
  out << "Hello " << name << ", how are you?\n";
}



auto main() -> int {
  try {
  sayGreeting(std::cout, "");
  } catch (std::exception const & e) {
    std::cout << e.what();
  } catch (...) {
    //Handle other exception types
  }

}
