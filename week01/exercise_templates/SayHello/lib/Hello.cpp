#include "Hello.hpp"

#include <ostream>

auto sayHello(std::ostream& out) -> void {
  out << "Hello World!\n";
}