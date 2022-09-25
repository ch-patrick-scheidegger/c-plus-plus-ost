#include "Sum.hpp"

#include <istream>

auto sumi(std::istream &in) -> int {
    auto result = 0;
    for (int next; in >> next; result += next);
    return result;
}

auto sumf(std::istream &in) -> double {
    auto result = 0.0;
    for (double next; in >> next; result += next);
    return result;
}

