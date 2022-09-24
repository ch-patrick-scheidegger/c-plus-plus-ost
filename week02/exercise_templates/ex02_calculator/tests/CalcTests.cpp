#include "Calc.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(testOnePlusOne) {
  auto result = calc(1, 1, '+');
  ASSERT_EQUAL(2, result);
}

auto createCalcSuite() -> cute::suite {
  cute::suite calcSuite{
    testOnePlusOne,
  };
  return calcSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto calcSuite = createCalcSuite();
  bool suiteResult = runner(calcSuite, "Calc Suite");

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}