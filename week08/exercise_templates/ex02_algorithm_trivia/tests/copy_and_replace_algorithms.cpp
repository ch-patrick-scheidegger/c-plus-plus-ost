#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

//Copy and replace algorithms (hints):
// * copy
// * copy_n
// * copy_if
// * copy_backward
// * swap_ranges
// * transform
// * replace
// * replace_if
// * replace_copy
// * replace_copy_if


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{5, 6, 7, 8, 0, 10};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{32, 64, 128, 256, 1, 1024};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			[](int i){return std::pow(2, i);});

	ASSERT_EQUAL(expected, out1);
}


TEST(test_algorithm_2) {
	auto in_out1 = std::vector{1, 2, 3, 2, 1, 2, 3, 2};
	auto expected = std::vector{1, 4, 3, 4, 1, 4, 3, 4};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			2,
			4);

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_3) {
	auto in1 = std::vector{1, 2, 3, 2, 1, 2, 3, 2};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{1, 4, 3, 4, 1, 4, 3, 4};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			2,
			4);

	ASSERT_EQUAL(expected, out1);
}


TEST(test_algorithm_4) {
	auto in_out1 = std::vector{1, 2, 3, 4};
	auto in_out2 = std::vector{5, 6, 7, 8};
	auto expected1 = std::vector{5, 6, 7, 8};
	auto expected2 = std::vector{1, 2, 3, 4};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			std::begin(in_out2));

	ASSERT_EQUAL(std::tie(expected1, expected2), std::tie(in_out1, in_out2));
}


TEST(test_algorithm_5) {
	auto in_out1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto expected = std::vector{1, 0, 0, 4, 0, 6, 0, 8};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			is_prime,
			0);

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_6) {
	auto in_out1 = std::vector{5, 6, 3, 7, 4, 0, 0, 0};
	auto expected = std::vector{5, 6, 3, 5, 6, 3, 7, 4};

	std::xxxxx(
			std::begin(in_out1),
			std::begin(in_out1) + 5,
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_7) {
	auto in1 = std::vector{5, 6, 3, 7, 9, 1, 5};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{5, 6, 3, 7, 9, 1, 5};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_8) {
	auto in1 = std::vector{5, 6, 3, 7, 10, 10, 5};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{5, 3, 7, 5};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			[](int const & i) {return i % 2;});

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_9) {
	auto in1 = std::vector{5, 6, 3, 7, 9, 1, 5};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{5, 6, 3, 7, 9, 1};

	std::xxxxx(
			std::begin(in1),
			6,
			std::back_inserter(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_10) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{1, 0, 0, 4, 0, 6, 0, 8};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			is_prime,
			0);

	ASSERT_EQUAL(expected, out1);
}

}

auto createCopyAndReplaceSuite() -> cute::suite {
	return cute::suite {
		"Copy and Replace Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
			test_algorithm_5,
			test_algorithm_6,
			test_algorithm_7,
			test_algorithm_8,
			test_algorithm_9,
			test_algorithm_10,
		}
	};
}
