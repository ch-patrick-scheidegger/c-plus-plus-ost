#include "PrintFunctionTable.hpp"

#include <ostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

auto printFunctionTable(std::ostream& out, double start, double end,
                        unsigned steps, std::function<auto(double)->double> f) -> void {
    double stepDelta = steps == 1 ? 0 : (end - start) / (steps - 1);
    std::vector<double> xValues {};
    std::generate_n(std::back_inserter(xValues), steps,
                    [n {0}, start, stepDelta]() mutable { return start + n++ * stepDelta; });
    std::vector<double> yValues {};
    std::generate_n(std::back_inserter(yValues), steps,
                    [n {0}, xValues, f]() mutable { return f(xValues[n++]); });

    out << "x    " << std::fixed << std::setprecision(1);
    std::ranges::copy(xValues, std::ostream_iterator<double>(out, " "));
    out << "\nf(x) ";
    std::ranges::copy(yValues, std::ostream_iterator<double>(out, " "));
    out << "\n";
}
