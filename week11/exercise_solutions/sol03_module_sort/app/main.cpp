#include "moduleSort.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  if (argc > 1) {
    auto input = std::ifstream{argv[1]};
    printSemesterTopological(input, std::cout);
  } else {
    using namespace std::string_literals;
    auto input = std::istringstream{
        R"(DB1 OO
        DB2 DB1
        Math
        OO
        AD1 OO
        CPI OO Math
        Thesis DB2 SE2 UI2
        SE1 AD1 CPI DB1
        SE2 DB1 SE1 UI1
        UI1 AD1
        UI2 UI1)"s};
    printSemesterTopological(input, std::cout);
  }
}
