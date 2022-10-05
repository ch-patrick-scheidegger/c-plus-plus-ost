#include "CountingToLower.hpp"

#include <iostream>

auto main() -> int {
    std::string input{};
    if (std::cin >> input) {
        auto changed = countingToLower(input);
        std::cout << "Changed " << changed << " characters: " << input;
    }
}