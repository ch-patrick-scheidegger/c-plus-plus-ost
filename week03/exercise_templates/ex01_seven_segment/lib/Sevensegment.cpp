#include "Sevensegment.hpp"

#include <ostream>
#include <array>

std::array<std::array<std::string, 5>, 10> const digits{
{
    {
    " - ",
    "| |",
    "   ",
    "| |",
    " - "
    },
    {
    "   ",
    "  |",
    "   ",
    "  |",
    "   "
    },
    {
    " - ",
    "  |",
    " - ",
    "|  ",
    " - "
    },
    {
    " - ",
    "  |",
    " - ",
    "  |",
    " - "
    },
    {
    "   ",
    "| |",
    " - ",
    "  |",
    "   "
    },
    {
    " - ",
    "|  ",
    " - ",
    "  |",
    " - "
    },
    {
    " - ",
    "|  ",
    " - ",
    "| |",
    " - "
    },
    {
    " - ",
    "  |",
    "   ",
    "  |",
    "   "
    },
    {
    " - ",
    "| |",
    " - ",
    "| |",
    " - "
    },
    {
    " - ",
    "| |",
    " - ",
    "  |",
    " - "
    },

}

};

auto printLargeDigit(int i, std::ostream& output) -> void {
    output << " - \n| |\n   \n| |\n - \n";
}

auto printLargeNumber(int i, std::ostream& output) -> void {
}