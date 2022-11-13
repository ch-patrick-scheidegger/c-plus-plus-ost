#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

//Property checking algorithms (hint):
// * all_of
// * any_of
// * none_of
// * mismatch
// * equal
// * is_permutation


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{2u, 3u, 5u, 6u, 7u};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(res);
}


TEST(test_algorithm_2) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto in2 = std::vector{1, 5, 7, 4, 2, 6, 3, 8};
	auto expected = true;

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_3) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto in2 = std::vector{1, 2, 3, 4, 0, 6, 7, 8};
	auto expected = std::make_pair(std::begin(in1) + 4, std::begin(in2) + 4);

	auto res = std::xxxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_4) {
	auto in1 = std::vector{2u, 3u, 5u, 6u, 7u};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(!res);
}

TEST(test_algorithm_5) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto in2 = std::vector{1, 2, 3, 4, 0, 6, 7, 8};
	auto expected = false;

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_6) {
	auto in1 = std::vector{1u, 4u, 6u, 8u, 9u};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(res);
}

}

auto createPropertyCheckingSuite() -> cute::suite {
	return cute::suite {
		"Property Checking Algorithms Suite",
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
