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

TEST(testAverageiZeroStream) {
  std::istringstream input{"0"};
  ASSERT_EQUAL(0, averagei(input));
}

TEST(testAveragei42Stream) {
  std::istringstream input{"42"};
  ASSERT_EQUAL(42, averagei(input));
}

TEST(testAverageiTwoNumbersInStream) {
  std::istringstream input{"123 78"};
  ASSERT_EQUAL(100, averagei(input));
}

TEST(testAverageiMultipleNumbersInStream) {
  std::istringstream input{"0 55 222 41 11"};
  ASSERT_EQUAL(65, averagei(input));
}

auto createAverageiSuite() -> cute::suite {
  cute::suite averageiSuite{
    "Averagei Suite",
    {
      testAverageiEmptyStream,
      testAverageiZeroStream,
      testAveragei42Stream,
      testAverageiTwoNumbersInStream,
      testAverageiMultipleNumbersInStream,
    }
  };
  return averageiSuite;
}


TEST(testAveragefEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0.0, averagef(input));
}

TEST(testAveragefZeroStream) {
  std::istringstream input{"0.0"};
  ASSERT_EQUAL(0.0, averagef(input));
}

TEST(testAveragef42Stream) {
  std::istringstream input{"42.0"};
  ASSERT_EQUAL(42.0, averagef(input));
}

TEST(testAveragefTwoNumbersInStream) {
  std::istringstream input{"123.5 77.5"};
  ASSERT_EQUAL(100.5, averagef(input));
}

TEST(testAveragefMultipleNumbersInStream) {
  std::istringstream input{"0.0 54.25 222.5 41.2 11.05"};
  ASSERT_EQUAL(65.8, averagef(input));
}

auto createAveragefSuite() -> cute::suite {
  cute::suite averagefSuite{
    "Averagef Suite",
    {
      testAveragefEmptyStream,
      testAveragefZeroStream,
      testAveragef42Stream,
      testAveragefTwoNumbersInStream,
      testAveragefMultipleNumbersInStream,
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