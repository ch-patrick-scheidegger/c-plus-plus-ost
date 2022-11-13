#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

//Sorted sequence algorithms (hint):
// * lower_bound
// * upper_bound
// * equal_range
// * binary_search
// * merge
// * inplace_merge

namespace {

TEST(test_algorithm_1) {
	std::vector<int> in_out1{2, 3, 8, 9, 10, 16, 1, 3, 7, 13, 15};
	std::vector<int> expected{1, 2, 3, 3, 7, 8, 9, 10, 13, 15, 16};

	std::xxxxx(
			std::begin(in_out1),
			std::begin(in_out1) + 6,
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_2) {
	std::vector<int> in1{1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			7);

	ASSERT(res);
}

TEST(test_algorithm_3) {
	std::vector<int> in1{1, 3, 7, 13, 15};
	std::vector<int> in2{2, 3, 8, 9, 10, 16};
	std::vector<int> out{};
	std::vector<int> expected{1, 2, 3, 3, 7, 8, 9, 10, 13, 15, 16};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2),
			std::back_inserter(out));

	ASSERT_EQUAL(expected, out);
}

TEST(test_algorithm_5) {
	std::vector<unsigned> in1{1, 1, 1, 2, 2, 2, 3, 4, 4};
	auto expected = std::make_pair(std::begin(in1) + 3, std::begin(in1) + 6);

	auto res = std::xxxxxx(
			std::begin(in1),
			std::end(in1),
			2);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_4) {
	std::vector<unsigned> in1{1, 1, 1, 2, 2, 2, 3, 4, 4};
	auto expected = std::begin(in1) + 3;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			2);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_6) {
	std::vector<unsigned> in1{1, 1, 1, 2, 2, 2, 3, 4, 4};
	auto expected = std::begin(in1) + 6;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			2);

	ASSERT_EQUAL(expected, res);
}

}

auto createSortedSequenceSuite() -> cute::suite {
	return cute::suite{
		"Sorted Sequence Algorithms Suite",
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
