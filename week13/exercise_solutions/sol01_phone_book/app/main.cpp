#include "entry.hpp"
#include <iostream>

auto main() -> int {
    auto entry = Entry{
        {"Felix", "Morgner"},
        "+5550102034",
        {"Oberseestrasse", 10, 8640, "Rapperswil"}
    };

    std::cout << entry << '\n';
}