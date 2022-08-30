#include "SayHello.hpp"

#include <ostream>

auto sayHello(std::ostream &out) -> void{
  out << "Hello, world!\n";
}