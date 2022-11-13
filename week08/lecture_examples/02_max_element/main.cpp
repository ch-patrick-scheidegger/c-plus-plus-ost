#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

#include <iterator>

auto maximum(std::vector<int> values) -> int {
  auto var = std::numeric_limits<int>::min();
  for (auto v : values) {
    if (v > var) {
      var = v;
    }
  }
  return var;
}

//auto maximum(std::vector<int> values) -> int {
//	if (values.empty()) {
//		return std::numeric_limits<int>::min();
//	}
//	return *std::max_element(begin(values), end(values));
//}

auto main(int argc, char **argv) -> int {
	auto values = std::vector{ 1, 2, 6, 4, 5, 3 };
	std::cout << maximum(values);
}
