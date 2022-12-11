#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "bed.hpp"

#include <iosfwd>

struct Triangle : Bed
{
    Triangle(double sideA, double sideB, double sideC);

    auto pegs() const -> unsigned override;
    auto ropes() const -> double override;
    auto seeds() const -> double override;

private:
    auto name() const -> std::string override;

    double sideA;
    double sideB;
    double sideC;
};

#endif
