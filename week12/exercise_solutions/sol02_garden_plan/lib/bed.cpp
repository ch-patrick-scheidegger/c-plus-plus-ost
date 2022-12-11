#include "bed.hpp"
#include <ostream>

auto Bed::print(std::ostream & output) const -> void {
    output << name()
           << " " << pegs()
           << " " << ropes()
           << " " << seeds();
}