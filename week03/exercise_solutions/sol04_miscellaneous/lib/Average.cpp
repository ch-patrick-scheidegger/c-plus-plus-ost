#include "Average.hpp"

#include <algorithm>
#include <istream>
#include <numeric>
#include <ranges>

auto averagei(std::istream &in) -> int {
  auto sum = 0;
  auto numberOfValues = 0u;
  std::ranges::for_each(std::ranges::istream_view<int>{in}, [&](auto value) {
    sum += value;
    numberOfValues++;
  });
  if (!numberOfValues) {
    return 0;
  }
  return sum / numberOfValues;
}

auto averagef(std::istream &in) -> double {
  auto sum = 0.0;
  auto numberOfValues = 0u;
  std::ranges::for_each(std::ranges::istream_view<double>{in}, [&](auto value) {
    sum += value;
    numberOfValues++;
  });
  if (!numberOfValues) {
    return 0;
  }
  return sum / numberOfValues;
}
