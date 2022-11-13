#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

struct Accumulator {
  int count{0};
  int accumulated_value{0};

  auto operator()(int value) -> void {
    count++;
    accumulated_value += value;
  }

	auto average() const -> int {
		return accumulated_value / count;
	}
};

auto average(std::vector<int> values) -> int {
  auto acc = Accumulator{};
  for(auto v : values) { acc(v); }
  return acc.average();
}

//auto average(std::vector<int> values) -> int{
//  Accumulator acc{};
//  return std::for_each(begin(values), end(values), acc).average();
//}

auto main(int argc, char **argv) -> int {
  auto values = std::vector{ 1, 2, 6, 4, 5, 3 };
  std::cout << average(values);
}
