#include "Tables.hpp"

#include <cstddef>
#include <istream>
#include <ostream>


auto printMultab(std::ostream &out, std::size_t limit) -> void {
    for (auto row = 1; row <= limit; row++) {
        for (auto column = 1; column <= limit; column++) {
            out.width(4);
            out << (row * column);
        }
        out << '\n';
    }
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
    for (auto row = 1; row <= limit; row++) {
        printFraction(out, row);
        for (auto column = 1; column <= limit; column++) {
            out << ' ';
            out.width(7);
            out << (static_cast<double>(row) / column);
        }
        out << '\n';
    }
}

auto fractab(std::istream &in, std::ostream &out) -> void {
    out << "Enter limit (max 10):\n";
    std::size_t limit{};
    if (in >> limit && limit <= 10) {
        printFractabHeader(out, limit);
        printFractab(out, limit);
    }
}