#include "square.hpp"

// TODO: Implement class square
auto Square::numberOfPegs() const -> int {
    return 4;
}

auto Square::stringLength() const -> int {
    return length * 4;
}

auto Square::seeds() const -> int {
    return length * length * 0.1;
}
