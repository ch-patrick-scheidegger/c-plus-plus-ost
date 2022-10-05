#include "CountingToLower.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <string>

auto countingToLower(std::string &input) -> std::size_t {
  auto numberOfUpperChars = std::ranges::count_if(input, ::isupper);
  std::ranges::transform(input, std::begin(input), ::tolower);
  return numberOfUpperChars;
}