#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int const minusIndex = 10;

auto splitDigits(int number) {
  std::string digits = std::to_string(number);
  std::vector<unsigned> indices(digits.size());
  transform(begin(digits), end(digits),
            begin(indices),
            [](char c) {
    return c == '-' ? minusIndex : c - '0';
  });
  return indices;
}


int main() {
	auto digits = splitDigits(-1234);
	copy(cbegin(digits), cend(digits), std::ostream_iterator<unsigned>{std::cout, "\n"});
}

