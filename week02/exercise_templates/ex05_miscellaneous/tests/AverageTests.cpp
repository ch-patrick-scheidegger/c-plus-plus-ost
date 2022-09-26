#include "Average.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testAverageiEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, averagei(input));
}


auto createAverageiSuite() -> cute::suite {
  cute::suite averageiSuite{
    "Averagei Suite",
    {
      testAverageiEmptyStream,
    }
  };
  return averageiSuite;
}


TEST(testAveragefEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0.0, averagef(input));
}


auto createAveragefSuite() -> cute::suite {
  cute::suite averagefSuite{
    "Averagef Suite",
    {
      testAveragefEmptyStream,
    }
  };
  return averagefSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createAverageiSuite());
  suiteResult &= runner(createAveragefSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}