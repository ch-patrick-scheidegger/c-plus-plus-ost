#include "Counting.hpp"

#include <ios>
#include <istream>
#include <string>

auto charc(std::istream &input) -> unsigned {
  auto numberOfChars = 0u;
  char consumedChar;
  while (input >> consumedChar) {
    numberOfChars++;
  }
  return numberOfChars;
}

auto allcharc(std::istream &input) -> unsigned {
  input >> std::noskipws;
  return charc(input);
}

auto wc(std::istream &input) -> unsigned {
  auto numberOfWords = 0u;
  std::string consumedWord;
  while (input >> consumedWord) {
    numberOfWords++;
  }
  return numberOfWords;
}

auto lc(std::istream &input) -> unsigned {
    auto numberOfLines = 0u;
    std::string consumedLine{};
    while (std::getline(input, consumedLine)) {
       numberOfLines++;
    }
    return numberOfLines;
}