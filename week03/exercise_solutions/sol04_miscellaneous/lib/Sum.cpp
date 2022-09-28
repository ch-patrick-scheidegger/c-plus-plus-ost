#include "Sum.hpp"

#include <istream>
#include <iterator>
#include <numeric>

auto sumi(std::istream &in) -> int {
    using InputIterator = std::istream_iterator<int>;
    return std::reduce(InputIterator{in}, InputIterator{});
}

auto sumf(std::istream &in) -> double {
    using InputIterator = std::istream_iterator<double>;
    return std::reduce(InputIterator{in}, InputIterator{});
}

