#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

auto printStreamState(std::stringstream const& s) -> void {
  std::cout << std::boolalpha;
  std::cout << "s.eof():  " << static_cast<bool>(s.eof()) << "\n";
  std::cout << "s.fail():  " << static_cast<bool>(s.fail()) << "\n";
  std::cout << "s.bad():  " << static_cast<bool>(s.bad()) << "\n";
  std::cout << "s.good():  " << static_cast<bool>(s.good()) << "\n";
  std::cout << "bool(s):  " << bool(s) << "\n";
  std::cout << "-----------------------------------------\n";
}

auto main(int argc, char** argv) -> int {
  std::stringstream s{"23 5"};
  printStreamState(s);
  int i{};

  s >> i;
  std::cout << "value after first read: " << i << "\n";
  printStreamState(s);
  s >> i;
  std::cout << "value after second read: " << i << "\n";
  printStreamState(s);
  s >> i;
  std::cout << "value after third read: " << i << "\n";
  printStreamState(s);
}