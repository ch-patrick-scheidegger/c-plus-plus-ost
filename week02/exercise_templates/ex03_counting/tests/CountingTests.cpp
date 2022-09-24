#include "Counting.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(testCharcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, charc(input));
}

auto createCarcSuite() -> cute::suite {
  cute::suite charcSuite{
    testCharcEmptyStream,
  };
  return charcSuite;
}

TEST(testAllcharcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, allcharc(input));
}

auto createAllcharcSuite() -> cute::suite {
  cute::suite allcharcSuite{
    testAllcharcEmptyStream,
  };
  return allcharcSuite;
}

TEST(testWcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, wc(input));
}

auto createWcSuite() -> cute::suite {
  cute::suite wcSuite{
    testWcEmptyStream,
  };
  return wcSuite;
}

TEST(testLcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, lc(input));
}

auto createLcSuite() -> cute::suite {
  cute::suite lcSuite{
    testLcEmptyStream,
  };
  return lcSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto charcSuite = createCarcSuite();
  bool suiteResult = runner(charcSuite, "Charc Suite");
  auto allcharcSuite = createAllcharcSuite();
  suiteResult &= runner(allcharcSuite, "Allcharc Suite");
  auto wcSuite = createWcSuite();
  suiteResult &= runner(wcSuite, "Wc Suite");
  auto lcSuite = createLcSuite();
  suiteResult &= runner(lcSuite, "Lc Suite");

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}