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
	std::vector<unsigned> in1{2, 3, 5, 6, 7};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(res);
}


TEST(test_algorithm_2) {
	std::vector<int> in1{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> in2{1, 5, 7, 4, 2, 6, 3, 8};
	auto expected = true;

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_3) {
	std::vector<int> in1{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> in2{1, 2, 3, 4, 0, 6, 7, 8};
	auto expected = std::make_pair(std::begin(in1) + 4, std::begin(in2) + 4);

	auto res = std::xxxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_4) {
	std::vector<unsigned> in1{2, 3, 5, 6, 7};

	bool res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT(!res);
}

TEST(test_algorithm_5) {
	std::vector<int> in1{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> in2{1, 2, 3, 4, 0, 6, 7, 8};
	auto expected = false;

	auto res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2));

	ASSERT_EQUAL(expected, res);
}


TEST(test_algorithm_6) {
	std::vector<unsigned> in1{1, 4, 6, 8, 9};

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
