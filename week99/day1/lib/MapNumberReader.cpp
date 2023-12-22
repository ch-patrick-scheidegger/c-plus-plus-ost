#include "MapNumberReader.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <array>

std::array<std::string, 9> spelledNumbers{{"one", "two", "three", "four",
                                           "five", "six", "seven", "eight", "nine"}};

auto getSumPerLine(std::string line) -> int {
    std::vector<char> numbers{};
    std::array<int, 9> numberPosition;
    std::fill(numberPosition.begin(), numberPosition.end(), 0);
    std::ranges::for_each(line, [&numbers, &numberPosition](char c) -> void {
        if(std::isdigit(c)) {
            numbers.push_back(c - 48);
        } else {
            for(int i = 0; i < spelledNumbers.size(); i++) {
                if(spelledNumbers[i][numberPosition[i]] == c) {
                    numberPosition[i]++;
                    if(numberPosition[i] == spelledNumbers[i].size()) {
                        numbers.push_back(i + 1);
                        numberPosition[i] = 0;
                    }
                }
            }
        }
    });
    return numbers.front() * 10 + numbers.back();
}

auto MapNumberReader::getSumOfFirstAndLastDigitPerLine(std::ifstream & file) -> int {
    std::string line{};
    std::vector<int> numberSumPerLine{};
    while (std::getline(file, line)) {
        numberSumPerLine.push_back(getSumPerLine(line));
    }
    return std::accumulate(numberSumPerLine.begin(), numberSumPerLine.end(), 0);
}
