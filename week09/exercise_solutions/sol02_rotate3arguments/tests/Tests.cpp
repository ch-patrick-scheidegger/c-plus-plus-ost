#include "rotate3arguments.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <tuple>

TEST(test_rotate_1_2_3) {
  int a{1}, b{2}, c{3};
  auto expected = std::make_tuple(2, 3, 1);

  rotate3arguments(a, b, c);

  ASSERT_EQUAL(expected, std::tie(a, b, c));
}

TEST(test_rotate_one_two_three) {
  auto a = "one", b = "two", c = "three";
  auto expected = std::make_tuple("two", "three", "one");

  rotate3arguments(a, b, c);

  ASSERT_EQUAL(expected, std::tie(a, b, c));
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Function Template 'rotate3arguments' Tests",
    {
      test_rotate_1_2_3,
      test_rotate_one_two_three,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
