#include "Counting.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testCharcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, charc(input));
}

auto createCarcSuite() -> cute::suite {
  cute::suite charcSuite{
    "Charc Suite",
    {
      testCharcEmptyStream,
    }
  };
  return charcSuite;
}

TEST(testAllcharcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, allcharc(input));
}


auto createAllcharcSuite() -> cute::suite {
  cute::suite allcharcSuite{
    "Allcharc Suite",
    {
      testAllcharcEmptyStream,
    }
  };
  return allcharcSuite;
}


TEST(testWcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, wc(input));
}


auto createWcSuite() -> cute::suite {
  cute::suite wcSuite{
    "Wc Suite",
    {
      testWcEmptyStream,
    }
  };
  return wcSuite;
}


TEST(testLcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, lc(input));
}

auto createSumiSuite() -> cute::suite {
  cute::suite lcSuite{
    "Lc Suite",
    {
      testLcEmptyStream,
    }
  };
  return lcSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createCarcSuite());
  suiteResult &= runner(createAllcharcSuite());
  suiteResult &= runner(createWcSuite());
  suiteResult &= runner(createSumiSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}