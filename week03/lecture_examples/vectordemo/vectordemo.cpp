#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

auto vectordemo_algorithms(std::ostream &outStream) -> void {
  std::vector<int> v{1, 2, 3, 4, 5};

  for (size_t i = 0; i < v.size(); ++i) {
    outStream << "v[" << i << "] = " << v[i] << '\n';
  }

  for (std::vector<int>::size_type i = 0; i < v.size(); ++i) {
    outStream << v.at(i) << '\n';
  }

  for (auto &j : v) {
    j *= 2;
  }

  for (auto const i : v) {
    outStream << "element: " << i << '\n';
  }

  for (auto it = begin(v); it != end(v); ++it) {
    outStream << (*it)++ << ", ";
  }

  outStream << '\n';
  for (auto it = cbegin(v); it != cend(v); ++it) {
    outStream << *it << ", ";
  }

  outStream << '\n';
  std::copy(std::cbegin(v), std::cend(v),
            std::ostream_iterator<int>{outStream, ", "});

  outStream << '\n';
  std::ranges::copy(v, std::ostream_iterator<int>{outStream, ", "});
}

// DO not write loops like this, use algorithms!
auto main() -> int { vectordemo_algorithms(std::cout); }
