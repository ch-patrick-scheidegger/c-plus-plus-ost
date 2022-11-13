#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main(int argc, char **argv) {
	auto r1 = std::vector{9, 12, 17, 23, 54, 57, 85, 95};
	auto r2 = std::vector{2, 30, 32, 41, 49, 63, 72, 88};
	auto d = std::vector(r1.size() + r2.size(), 0);
	std::merge(begin(r1), end(r1), begin(r2), end(r2), begin(d));

	std::copy(begin(d), end(d), std::ostream_iterator<int>{std::cout, ", "});
}