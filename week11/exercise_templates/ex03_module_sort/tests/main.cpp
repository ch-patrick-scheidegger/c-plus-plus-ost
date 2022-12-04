#include "moduleSort.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

TEST(start_writing_tests) {
    ASSERTM("Start writing tests!", false);
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "ModuleSort Tests",
    {
      start_writing_tests,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
