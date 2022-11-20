#include "median.hpp"

#include <cstdlib>
#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

TEST(test_median_with_1_2_3) {
  ASSERT_EQUAL(2, median(1, 2, 3));
}

TEST(test_median_int_right_value) {
  ASSERT_EQUAL(5, median(3, 9, 5));
}

TEST(test_median_double) {
  ASSERT_EQUAL_DELTA(7.0, median(7.0, 7.1, 6.9), 0.0001);
}

TEST(test_medianString) {
  ASSERT_EQUAL("four", median<std::string>("four", "five", "six"));
}

TEST(test_medianCharPtr) {
  ASSERT_EQUAL("four", median("five", "four", "six"));
}

TEST(test_median_all_int_permutations) {
  std::vector<int> v{3, 5, 9};
  do {
    ASSERT_EQUAL(5, median(v[0], v[1], v[2]));
  } while (std::next_permutation(v.begin(), v.end()));
}

TEST(test_median_string_literals_all_permutations) {
  std::vector<char const *> v{"aa", "ab", "ac"};
  do {
    ASSERT_EQUAL("ab", median(v[0], v[1], v[2]));
  } while (std::next_permutation(v.begin(), v.end()));
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Function Template 'median' Tests",
    {
      test_median_double,
      test_median_int_right_value,
      test_medianString,
      test_medianCharPtr,
      test_median_all_int_permutations,
      test_median_with_1_2_3,
      test_median_string_literals_all_permutations,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
