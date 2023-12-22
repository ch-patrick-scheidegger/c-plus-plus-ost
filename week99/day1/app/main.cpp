#include "MapNumberReader.hpp"

#include <iostream>

int main() {
    std::ifstream file("C:\\Users\\Pat\\CLionProjects\\cpl\\week99\\day1\\app\\map.txt");
    MapNumberReader r{};
    int result = r.getSumOfFirstAndLastDigitPerLine(file);
    std::cout << "Result: " << result;
}
