#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>


//Find and related algorithms (hint):
// * find
// * find_if
// * find_if_not
// * find_end
// * find_first_of
// * adjacent_find
// * count
// * count_if
// * search
// * search_n


namespace {

TEST(test_algorithm_1) {
	auto in1 = std::vector{1, 2, 1, 2, 1, 2, 3, 1, 2, 3};
	auto in2 = std::vector{1, 2, 3};
	auto expected = std::begin(in1) + 4;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2));

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_2) {
	auto in1 = std::vector{1, 2, 3, 2, 1, 2, 3, 4, 3, 2};
	int expected = 4;

	int res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			2);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_3) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7};
	auto expected = std::begin(in1) + 4;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			5);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_4) {
	auto in1 = std::vector{5, 6, 4, 7, 6, 2, 1};
	auto in2 = std::vector{1, 2, 3};
	auto expected = std::begin(in1) + 5;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2));

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_5) {
	auto in1 = std::vector{1, 1, 2, 2, 2, 1, 1, 1, 3, 3};
	auto expected = std::begin(in1) + 5;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			3,
			1);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_6) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7};
	auto expected = std::begin(in1) + 1;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_7) {
	auto in1 = std::vector{5, 6, 4, 7, 7, 2, 2};
	auto expected = std::begin(in1) + 3;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1));

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_8) {
	auto in1 = std::vector{2, 3, 5, 7, 11, 13, 17};
	auto expected = std::end(in1);

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_9) {
	auto in1 = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int expected = 4;

	int res = std::xxxxx(
			std::begin(in1),
			std::end(in1),
			is_prime);

	ASSERT_EQUAL(expected, res);
}

TEST(test_algorithm_10) {
	auto in1 = std::vector{1, 2, 3, 1, 2, 3, 1};
	auto in2 = std::vector{1, 2, 3};
	auto expected = std::begin(in1) + 3;

	auto res = std::xxx(
			std::begin(in1),
			std::end(in1),
			std::begin(in2),
			std::end(in2));

	ASSERT_EQUAL(expected, res);
}

}

auto createFindSuite() -> cute::suite {
	return cute::suite{
		"Find Algorithms Suite",
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
