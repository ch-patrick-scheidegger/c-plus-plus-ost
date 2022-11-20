#include "woccurrence.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <fstream>
#include <sstream>

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "'wordLineOccurrence' Tests",
    {
      // ADD YOUR TESTS
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
