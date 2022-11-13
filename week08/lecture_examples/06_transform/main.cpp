#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

auto main(int argc, char **argv) -> int {
	auto counts = std::vector{ 3, 0, 1, 4, 0, 2 };
	auto letters = std::vector{ 'g', 'a', 'u', 'y', 'f', 'o' };
	auto combined = std::vector<std::string>{};
	auto times = [](int i, char c) {return std::string(i, c);};
	std::transform(begin(counts), end(counts), begin(letters), std::back_inserter(combined), times);
	std::copy(begin(combined), end(combined), std::ostream_iterator<std::string>{std::cout, ", "});
}
