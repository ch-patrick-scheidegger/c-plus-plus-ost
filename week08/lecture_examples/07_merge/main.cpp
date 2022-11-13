#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main(int argc, char **argv) {
	std::vector<int> r1{9, 12, 17, 23, 54, 57, 85, 95};
	std::vector<int> r2{2, 30, 32, 41, 49, 63, 72, 88};
	std::vector<int> d(r1.size() + r2.size(), 0);
	std::merge(begin(r1), end(r1), begin(r2), end(r2), begin(d));

	std::copy(begin(d), end(d), std::ostream_iterator<int>{std::cout, ", "});
}