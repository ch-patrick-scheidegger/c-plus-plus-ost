#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

int main(int argc, char **argv) {
	std::vector<int> counts { 3, 0, 1, 4, 0, 2 };
	std::vector<char> letters { 'g', 'a', 'u', 'y', 'f', 'o' };
	std::vector<std::string> combined { };
	auto times = [](int i, char c) {return std::string(i, c);};
	std::transform(begin(counts), end(counts), begin(letters), std::back_inserter(combined), times);
	std::copy(begin(combined), end(combined), std::ostream_iterator<std::string>{std::cout, ", "});
}
