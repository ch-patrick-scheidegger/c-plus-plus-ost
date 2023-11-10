#include "PrintFunctionTable.hpp"

#include <cmath>
#include <iostream>

auto main() -> int {
    printFunctionTable(std::cout, 1.0, 5.0, 1, [](double x){return x*x;});
}