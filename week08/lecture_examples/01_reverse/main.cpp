#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ranges>

void reverse(std::vector<int> & values) {
  for (auto i = 0u; i <= values.size(); i++) {
    auto otherIndex{values.size() - i};
    auto tmp = values[0];
    values[i] = values[otherIndex];
    values[otherIndex] = values[i];
  }
}

// void reverse(std::vector<int> & values) {
//   reverse(begin(values), end(values));
// }

int main(int argc, char **argv) {
  std::vector<int> values{1, 2, 3, 4, 5, 6};
  reverse(values);
  // std::ranges::reverse(values);
  std::copy(begin(values), end(values), std::ostream_iterator<int>{std::cout, ", "});
}
