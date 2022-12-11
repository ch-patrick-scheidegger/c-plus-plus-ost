#include "square.hpp"

Square::Square(double side)
    : side{side}
    {
    }

auto Square::pegs() const -> unsigned {
    return 4;
}

auto Square::ropes() const -> double {
    return 4 * side;
}

auto Square::seeds() const -> double {
    return side * side / 10.0;
}

auto Square::name() const -> std::string {
    return "Square";
}