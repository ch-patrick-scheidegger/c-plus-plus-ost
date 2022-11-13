#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

struct Accumulator {
  int count{0};
  int accumulated_value{0};
  void operator()(int value) {
    count++;
    accumulated_value += value;
  }
	int average() const {
		return accumulated_value / count;
	}
  int sum() const;
};

int average(std::vector<int> values) {
  Accumulator acc{};
  for(auto v : values) { acc(v); }
  return acc.average();
}

//int average(std::vector<int> values) {
//  Accumulator acc{};
//  return std::for_each(begin(values), end(values), acc).average();
//}

int main(int argc, char **argv) {
	std::vector<int> values { 1, 2, 6, 4, 5, 3 };
	std::cout << average(values);
}
