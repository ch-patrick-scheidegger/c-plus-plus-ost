#include "PrintFunctionTable.hpp"
#include <algorithm>
#include <iomanip>
#include <ostream>
#include <iterator>

auto printFunctionTable(std::ostream& out, double start, double end, unsigned steps, std::function<auto(double)->double> f) -> void {
    std::vector<double> xs(steps);
    auto stride = (steps > 1) ? (end - start) / (steps - 1) : 1;
    std::ranges::generate(xs, [=, i = 0]() mutable {return start + stride * i++;});
    out << "x    " << std::fixed << std::setprecision(1);
    std::ostream_iterator<double>outputIterator{out, " "};
    std::ranges::copy(xs, outputIterator);
    out << "\nf(x) ";
    std::ranges::transform(xs, outputIterator, f);
    out << '\n';
}
