#include "Sum.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testSumiEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, sumi(input));
}

auto createSumiSuite() -> cute::suite {
  cute::suite sumiSuite{
    "Sumi Suite",
    {
      testSumiEmptyStream,
    }
  };
  return sumiSuite;
}


TEST(testSumfEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0.0, sumf(input));
}

auto createSumfSuite() -> cute::suite {
  cute::suite sumfSuite{
    "Sumf Suite",
    {
      testSumfEmptyStream,
    }
  };
  return sumfSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createSumiSuite());
  suiteResult &= runner(createSumfSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}