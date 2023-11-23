#include "rotate3arguments.hpp"

#include <cute/cute.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <cute/cute_runner.h>

TEST(should_rotate_int_pointers) {
    // Given
    int a = 1;
    int b = 2;
    int c = 3;
    // when
    rotate3arguments(a, b, c);
    // then
    ASSERT_EQUAL(2, a);
    ASSERT_EQUAL(3, b);
    ASSERT_EQUAL(1, c);
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Function Template 'rotate3arguments' Tests",
    {
            should_rotate_int_pointers,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
