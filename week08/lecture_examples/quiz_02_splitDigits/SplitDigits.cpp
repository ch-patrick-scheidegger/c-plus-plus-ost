#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

auto const minusIndex = 10;

auto splitDigits(int number) {
  auto digits = std::to_string(number);
  auto indices = std::vector<unsigned>(digits.size());
  transform(begin(digits), end(digits),
            begin(indices),
            [](char c) {
    return c == '-' ? minusIndex : c - '0';
  });
  return indices;
}


auto main() -> int {
	auto digits = splitDigits(-1234);
	copy(cbegin(digits), cend(digits), std::ostream_iterator<unsigned>{std::cout, "\n"});
}

