#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "bed.hpp"

#include <iosfwd>

struct Square : Bed
{
    Square(double side);

    auto pegs() const -> unsigned override;
    auto ropes() const -> double override;
    auto seeds() const -> double override;

private:
    auto name() const -> std::string override;

    double side;
};

#endif
