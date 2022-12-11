#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "bed.hpp"

#include <iosfwd>

struct Diamond : Bed
{
    Diamond(double side, double angle);

    auto pegs() const -> unsigned override;
    auto ropes() const -> double override;
    auto seeds() const -> double override;

private:
    auto name() const -> std::string override;

    double side;
    double angle;
};

#endif
