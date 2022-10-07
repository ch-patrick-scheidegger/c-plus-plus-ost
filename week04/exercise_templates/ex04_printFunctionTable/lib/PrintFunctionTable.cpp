#include "PrintFunctionTable.hpp"

#include <ostream>


auto printFunctionTable(std::ostream& out, double start, double end, unsigned steps, std::function<auto(double)->double> f) -> void {

    out << "x    \nf(x) \n";
}
