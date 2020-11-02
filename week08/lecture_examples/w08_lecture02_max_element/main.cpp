#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

#include <iterator>

int maximum(std::vector<int> values) {
  int var = std::numeric_limits<int>::min();
  for (auto v : values) {
    if (v > var) {
      var = v;
    }
  }
  return var;
}

//int maximum(std::vector<int> values) {
//	if (values.empty()) {
//		return std::numeric_limits<int>::min();
//	}
//	return *std::max_element(begin(values), end(values));
//}

int main(int argc, char **argv) {
	std::vector<int> values { 1, 2, 6, 4, 5, 3 };
	std::cout << maximum(values);
}
