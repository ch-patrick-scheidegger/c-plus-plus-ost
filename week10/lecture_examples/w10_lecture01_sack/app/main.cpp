#include "sack.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

auto main() -> int {
  Sack<char> scrabble_letters{};

  for (char c = 'A'; c <= 'Z'; ++c) {
    scrabble_letters.putInto(c);
  }

  auto values = std::vector<int>{scrabble_letters};
  std::ranges::copy(values, std::ostream_iterator<int>{std::cout, "; "});
  std::cout << '\n';

  while (!scrabble_letters.empty()) {
    std::cout << "play letter: " << scrabble_letters.getOut() << '\n';
  }
}
