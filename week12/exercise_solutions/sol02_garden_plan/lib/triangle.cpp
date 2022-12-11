#include "triangle.hpp"
#include <cmath>
#include <string>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : sideA{sideA}
    , sideB{sideB}
    , sideC{sideC}
    {
    }

auto Triangle::pegs() const -> unsigned {
    return 3;
}

auto Triangle::ropes() const -> double {
    return sideA + sideB + sideC;
}

auto Triangle::seeds() const -> double {
    auto semi_perimeter = ropes() / 2;
    auto squared_area = semi_perimeter * (semi_perimeter - sideA)
                                               * (semi_perimeter - sideB)
                                               * (semi_perimeter - sideC);
    return std::sqrt(squared_area) / 10.0;
}

auto Triangle::name() const -> std::string {
    return "Triangle";
}