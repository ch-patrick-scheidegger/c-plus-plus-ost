#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>

//Remove, unique and rotate algorithms (hint):
// * remove
// * remove_if
// * remove_copy
// * remove_copy_if
// * unique
// * unique_copy
// * reverse
// * reverse_copy
// * rotate
// * rotate_copy
// * next_permutation
// * prev_permutation


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{5, 6, 7, 8, 0, 10};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{10, 0, 8, 7, 6, 5};

	std::xxxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_2) {
	auto in_out1 = std::vector{4, 1, 2, 3};
	auto expected = std::vector{3, 4, 2, 1};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_3) {
	auto in_out1 = std::vector{1, 1, 3, 3, 4, 2, 2, 2};
	auto expected = std::vector{1, 3, 4, 2};

	auto new_end = std::xxx(
			std::begin(in_out1),
			std::end(in_out1));

	ASSERT_EQUAL_RANGES(std::begin(expected), std::end(expected), std::begin(in_out1), new_end);
}

TEST(test_algorithm_4) {
	auto in_out1 = std::vector{1, 2, 3, 2, 1, 2, 3, 2};
	auto expected = std::vector{1, 3, 1, 3};

	auto new_end = std::xxx(
			std::begin(in_out1),
			std::end(in_out1),
			2);

	ASSERT_EQUAL_RANGES(std::begin(expected), std::end(expected), std::begin(in_out1), new_end);
}

TEST(test_algorithm_5) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{5, 6, 7, 8, 9, 1, 2, 3, 4};

	std::xxxxx(
			std::begin(in1),
			std::begin(in1) + 4,
			std::end(in1),
			std::back_inserter(out1));

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_6) {
	auto in_out1 = std::vector{5, 6, 7, 8, 0, 10};
	auto expected = std::vector{10, 0, 8, 7, 6, 5};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_7) {
	auto in_out1 = std::vector{4, 1, 2, 3};
	auto expected = std::vector{4, 1, 3, 2};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}

TEST(test_algorithm_8) {
	auto in_out1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto expected = std::vector{5, 6, 7, 8, 9, 1, 2, 3, 4};

	std::xxxxx(
			std::begin(in_out1),
			std::begin(in_out1) + 4,
			std::end(in_out1));

	ASSERT_EQUAL(expected, in_out1);
}


TEST(test_algorithm_9) {
	auto in_out1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto expected = std::vector{1, 4, 6, 8};

	auto new_end = std::xxx(
			std::begin(in_out1),
			std::end(in_out1),
			is_prime);

	ASSERT_EQUAL_RANGES(std::begin(expected), std::end(expected), std::begin(in_out1), new_end);
}

TEST(test_algorithm_10) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{1, 4, 6, 8};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			is_prime);

	ASSERT_EQUAL(expected, out1);
}


TEST(test_algorithm_11) {
	auto in1 = std::vector{1, 2, 3, 2, 1, 2, 3, 2};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{1, 3, 1, 3};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1),
			2);

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_12) {
	auto in1 = std::vector{1, 1, 3, 3, 4, 2, 2, 2};
	auto out1 = std::vector<int>{};
	auto expected = std::vector{1, 3, 4, 2};

	std::xxxxx(
			std::begin(in1),
			std::end(in1),
			std::back_inserter(out1));

	ASSERT_EQUAL(expected, out1);
}

}

auto createRemoveUniqueRotateSuite() -> cute::suite {
	return cute::suite{
		"Remove, Unique, Rotate Algorithms Suite",
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
			test_algorithm_11,
			test_algorithm_12,
		}
	};
}
