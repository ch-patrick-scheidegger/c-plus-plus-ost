#include "Average.hpp"

#include <istream>

auto averagei(std::istream &in) -> int {
    auto result = 0;
    auto numberOfValues = 0u;
    for (int next; in >> next; result += next, numberOfValues++);
    if (!numberOfValues) {
        return 0;
    }  
    return result / numberOfValues;
   
}

auto averagef(std::istream &in) -> double {
    auto result = 0.0;
    auto numberOfValues = 0u;
    for (double next; in >> next; result += next, numberOfValues++);
    if (!numberOfValues) {
        return 0.0;
    }  
    return result / numberOfValues;
}

