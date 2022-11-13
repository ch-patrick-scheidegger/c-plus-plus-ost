#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ranges>

auto reverse(std::vector<int> & values) -> void {
  for (auto i = 0u; i <= values.size(); i++) {
    auto otherIndex{values.size() - i};
    auto tmp = values[0];
    values[i] = values[otherIndex];
    values[otherIndex] = values[i];
  }
}

// auto reverse(std::vector<int> & values) -> void {
//   reverse(begin(values), end(values));
// }

auto main(int argc, char **argv) -> int {
  auto values = std::vector{1, 2, 3, 4, 5, 6};
  reverse(values);
  // std::ranges::reverse(values);
  std::copy(begin(values), end(values), std::ostream_iterator<int>{std::cout, ", "});
}
