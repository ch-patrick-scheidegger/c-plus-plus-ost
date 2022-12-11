#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "bed.hpp"

#include <iosfwd>

struct Rectangle : Bed
{
    Rectangle(double shortSide, double longSide);

    auto pegs() const -> unsigned override;
    auto ropes() const -> double override;
    auto seeds() const -> double override;

private:
    auto name() const -> std::string override;

    double shortSide;
    double longSide;
};

#endif
