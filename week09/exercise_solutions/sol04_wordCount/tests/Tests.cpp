#include "wcount.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(test_wcount_for_empty_input_is_0) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, wcount(input));
}

TEST(test_wcount_for_one_input_line) {
  std::istringstream input{
      "Asterix, Obelix und Mirculix marschieren durch den Wald."};
  ASSERT_EQUAL(8, wcount(input));
}

TEST(test_wcount_for_multiple_input_lines) {
  std::istringstream input{"Alpha\nBeta\nGamma\nDelta\nEpsilon"};
  ASSERT_EQUAL(5, wcount(input));
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "wordCount Tests",
    {
      test_wcount_for_empty_input_is_0,
      test_wcount_for_one_input_line,
      test_wcount_for_multiple_input_lines,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
