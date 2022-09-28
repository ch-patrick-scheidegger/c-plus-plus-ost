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

TEST(testSumiZeroStream) {
  std::istringstream input{"0"};
  ASSERT_EQUAL(0, sumi(input));
}

TEST(testSumi42Stream) {
  std::istringstream input{"42"};
  ASSERT_EQUAL(42, sumi(input));
}

TEST(testSumiTwoNumbersInStream) {
  std::istringstream input{"123 78"};
  ASSERT_EQUAL(201, sumi(input));
}

TEST(testSumiMultipleNumbersInStream) {
  std::istringstream input{"0 55 222 41 11"};
  ASSERT_EQUAL(329, sumi(input));
}

auto createSumiSuite() -> cute::suite {
  cute::suite sumiSuite{
    "Sumi Suite",
    {
      testSumiEmptyStream,
      testSumiZeroStream,
      testSumi42Stream,
      testSumiTwoNumbersInStream,
      testSumiMultipleNumbersInStream,
    }
  };
  return sumiSuite;
}


TEST(testSumfEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0.0, sumf(input));
}

TEST(testSumfZeroStream) {
  std::istringstream input{"0.0"};
  ASSERT_EQUAL(0.0, sumf(input));
}

TEST(testSumf42Stream) {
  std::istringstream input{"42.0"};
  ASSERT_EQUAL(42.0, sumf(input));
}

TEST(testSumfTwoNumbersInStream) {
  std::istringstream input{"123.5 77.5"};
  ASSERT_EQUAL(201.0, sumf(input));
}

TEST(testSumfMultipleNumbersInStream) {
  std::istringstream input{"0 54.25 222.5 41.2 11.05"};
  ASSERT_EQUAL(329.0, sumf(input));
}

auto createSumfSuite() -> cute::suite {
  cute::suite sumfSuite{
    "Sumf Suite",
    {
      testSumfEmptyStream,
      testSumfZeroStream,
      testSumf42Stream,
      testSumfTwoNumbersInStream,
      testSumfMultipleNumbersInStream,
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