#include "diamond.hpp"

#include <cmath>
#include <numbers>

Diamond::Diamond(double side, double angleInDegrees)
    : side{side}
    , angle{angleInDegrees * std::numbers::pi / 180.0}
    {
    }

auto Diamond::pegs() const -> unsigned {
    return 4;
}

auto Diamond::ropes() const -> double {
    return 4 * side;
}

auto Diamond::seeds() const -> double {
    return side * side * std::sin(angle) / 10.0;
}

auto Diamond::name() const -> std::string {
    return "Diamond";
}