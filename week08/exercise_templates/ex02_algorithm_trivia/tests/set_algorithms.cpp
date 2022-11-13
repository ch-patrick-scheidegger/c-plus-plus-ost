#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>

//Set algorithms (hint):
// * includes
// * set_union
// * set_intersection
// * set_difference
// * set_symmetric_difference


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto in2 = std::vector{4, 5, 6, 9, 10, 11, 12};
	auto out = std::vector<int>{};
	auto expected = std::vector{4, 5, 6, 9};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2),
			std::back_inserter(out));

	ASSERT_EQUAL(expected, out);
}

TEST(test_algorithm_2) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto in2 = std::vector{4, 5, 6, 9, 10, 11, 12};
	auto out = std::vector<int>{};
	auto expected = std::vector{1, 2, 3, 7, 8};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2),
			std::back_inserter(out));

	ASSERT_EQUAL(expected, out);
}

TEST(test_algorithm_3) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto in2 = std::vector{4, 5, 6, 9, 10, 11, 12};
	auto out = std::vector<int>{};
	auto expected = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2),
			std::back_inserter(out));

	ASSERT_EQUAL(expected, out);
}


TEST(test_algorithm_4) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto in2 = std::vector{4, 5, 6, 9, 10, 11, 12};
	auto out = std::vector<int>{};
	auto expected = std::vector{1, 2, 3, 7, 8, 10, 11, 12};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2),
			std::back_inserter(out));

	ASSERT_EQUAL(expected, out);
}


TEST(test_algorithm_5) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto in2 = std::vector{2, 3, 4, 7, 8, 9};

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2));

	ASSERT(res);
}

}

auto createSetSuite() -> cute::suite {
	return cute::suite{
		"Set Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
			test_algorithm_5,
		}
	};
}
