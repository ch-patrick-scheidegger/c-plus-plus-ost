#ifndef PRINT_FUNCTION_TABLE_HPP_
#define PRINT_FUNCTION_TABLE_HPP_

#include <functional>
#include <iosfwd>

auto printFunctionTable(std::ostream& out, double start, double end, unsigned steps, std::function<auto(double)->double> f) -> void;

#endif