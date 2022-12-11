#include "rectangle.hpp"

Rectangle::Rectangle(double shortSide, double longSide)
    : shortSide{shortSide}
    , longSide{longSide}
    {
    }

auto Rectangle::pegs() const -> unsigned {
    return 4;
}

auto Rectangle::ropes() const -> double {
    return 2 * shortSide + 2 * longSide;
}

auto Rectangle::seeds() const -> double {
    return shortSide * longSide / 10.0;
}

auto Rectangle::name() const -> std::string {
    return "Rectangle";
}