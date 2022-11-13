#include "algorithm_replacements.h"

#include <cute/cute.h>

#include <vector>
#include <algorithm>
#include <iterator>

//Fill and generate algorithms (hints):
// * fill
// * fill_n
// * generate
// * generate_n

namespace {

TEST(test_algorithm_1) {
	std::vector<int> in_out1{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> expected{42, 42, 42, 42, 5, 6, 7, 8};

	std::xxxxx(
			std::begin(in_out1),
			4,
			42);

	ASSERT_EQUAL(expected, in_out1);
}


TEST(test_algorithm_2) {
	std::vector<int> out1{};
	std::vector<int> expected{100, 101, 102, 103, 104};
	int start = 100;

	std::xxxxx(
			std::back_inserter(out1),
			5,
			[start]() mutable {return start++;});

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_3) {
	std::vector<int> out1(5);
	std::vector<int> expected{100, 101, 102, 103, 104};
	int start = 100;

	std::xxxxx(
			std::begin(out1),
			std::end(out1),
			[start]() mutable {return start++;});

	ASSERT_EQUAL(expected, out1);
}

TEST(test_algorithm_4) {
	std::vector<int> in_out1{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> expected{42, 42, 42, 42, 42, 42, 42, 42};

	std::xxxxx(
			std::begin(in_out1),
			std::end(in_out1),
			42);

	ASSERT_EQUAL(expected, in_out1);
}

}

auto createFillAndGenerateSuite() -> cute::suite {
	return cute::suite{
		"Fill and Generate Algorithms Suite",
		{
			test_algorithm_1,
			test_algorithm_2,
			test_algorithm_3,
			test_algorithm_4,
		}
	};
}
