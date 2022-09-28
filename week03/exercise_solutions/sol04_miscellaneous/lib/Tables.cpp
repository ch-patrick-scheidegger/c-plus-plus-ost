#include "Tables.hpp"

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <istream>
#include <iterator>
#include <ostream>
#include <ranges>
#include <vector>

auto printMultab(std::ostream &out, std::size_t limit) -> void {
  std::vector<int> v(limit);
  std::ranges::generate(v, [i = 1]() mutable { return i++; });
  std::ranges::for_each(v, [&](int row) {
    std::ranges::for_each(
        v, [row, &out](int col) { out << std::setw(4) << row * col; });
    out << '\n';
  });
}

auto multab(std::istream &in, std::ostream &out) -> void {
  out << "Enter limit (max 30):\n";
  std::size_t limit{};
  if (in >> limit && limit <= 30) {
    printMultab(out, limit);
  }
}

auto printFraction(std::ostream &out, double value) -> void {
  out << ' ';
  out.width(7);
  out.precision(5);
  out << value;
}


auto printFractabHeader(std::ostream &out, std::size_t limit) -> void {
    for (auto column = 0; column <= limit; column++) {
        printFraction(out, column);
    }
    out << '\n';
}

auto printFractab(std::ostream &out, std::size_t limit) -> void {
  std::vector<int> v(limit);
  std::ranges::generate(v, [i = 1]() mutable { return i++; });
  std::ranges::for_each(v, [&](int row) {
    printFraction(out, row);
    std::ranges::for_each(
        v, [row, &out](double col) { printFraction(out, row / col); });
    out << '\n';
  });
}

auto fractab(std::istream &in, std::ostream &out) -> void {
  out << "Enter limit (max 10):\n";
  std::size_t limit{};
  if (in >> limit && limit <= 10) {
    printFractabHeader(out, limit);
    printFractab(out, limit);
  }
}