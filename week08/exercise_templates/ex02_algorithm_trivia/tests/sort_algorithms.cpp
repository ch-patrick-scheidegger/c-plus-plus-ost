#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>

//Sort algorithms (hint):
// * sort
// * stable_sort
// * partial_sort
// * partial_sort_copy
// * is_sorted
// * nth_element


namespace {

TEST(test_algorithm_1) {
	auto in_out1 = std::vector{2, 3, 5, 7, 1, 4, 6, 8, 9};
	auto expected = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_2) {
	auto in1 = std::vector{2, 5, 3, 7, 1, 4, 6, 8, 9};
	auto out1 = std::vector{0, 0, 0, 0, 0};
	auto expected = std::vector{1, 2, 3, 4, 5};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(out1),
			std::end(out1));

	ASSERT_EQUAL(expected, out1);
}


TEST(test_algorithm_3) {
	auto in1 = std::vector{2u, 3u, 5u, 6u, 7u};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1));

	ASSERT(res);
}


TEST(test_algorithm_4) {
	auto in_out1 = std::vector{2, 5, 3, 7, 1, 4, 6, 8, 9};
	auto expected = std::vector{1, 2, 3, 4};

	std::xxxxx(
			std::begin(in_out1),
			std::begin(in_out1) + 4,
			std::end(in_out1));

	ASSERT_EQUAL_RANGES(std::begin(expected), std::end(expected), std::begin(in_out1), std::begin(in_out1) + 4);
}


TEST(test_algorithm_5) {
	auto in_out1 = std::vector<std::pair<int, int>>{{2, 1}, {1, 0}, {1, 2}, {1, 4}, {2, 3}};
	auto expected = std::vector<std::pair<int, int>>{{1, 0}, {1, 2}, {1, 4}, {2, 1}, {2, 3}};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			[](std::pair<int, int> l, std::pair<int, int> r) {return l.first < r.first;});

	ASSERT_EQUAL(expected, in_out1);
}


TEST(test_algorithm_6) {
	auto in_out1 = std::vector{45u, 27u, 73u, 15u, 95u, 64u, 44u, 0u, 99u};

	std::xxxxx(
			std::begin(in_out1),
			std::begin(in_out1) + 3,
			std::end(in_out1));

	ASSERT_EQUAL(44, *(std::begin(in_out1) + 3));
}

}

auto createSortSuite() -> cute::suite {
	return cute::suite{
		"Sort Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
			test_algorithm_5,
			test_algorithm_6,
		}
	};
}
