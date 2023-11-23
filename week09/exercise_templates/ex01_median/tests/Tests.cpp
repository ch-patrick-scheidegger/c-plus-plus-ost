#include "median.hpp"

#include <cute/cute.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <cute/cute_runner.h>

TEST(should_return_correct_int_median) {
    // given .. when
    auto result = median(6, 1, 4);
    // then
    ASSERT_EQUAL(4, result);
}

TEST(should_return_correct_double_median) {
    // given .. when
    auto result = median(1.1, 2.2, 3.3);
    // then
    ASSERT_EQUAL(2.2, result);
}

TEST(should_return_correct_char_median) {
    // given .. when
    auto result = median('b', 'c', 'a');
    // then
    ASSERT_EQUAL('b', result);
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Function Template 'median' Tests",
    {
            should_return_correct_int_median,
            should_return_correct_double_median,
            should_return_correct_char_median,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}