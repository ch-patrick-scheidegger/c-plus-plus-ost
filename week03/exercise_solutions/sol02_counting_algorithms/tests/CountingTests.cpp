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

TEST(testCharcSimpleWordInStream) {
  std::istringstream input{"Counting"};
  ASSERT_EQUAL(8, charc(input));
}

TEST(testCharcHelloWorldInStream) {
  std::istringstream input{"Hello, world!"};
  ASSERT_EQUAL(12, charc(input));
}

TEST(testCharcMultipleLinesInStream) {
  std::istringstream input{"Counting some characters\nin my stream\n "};
  ASSERT_EQUAL(32, charc(input));
}

auto createCarcSuite() -> cute::suite {
  cute::suite charcSuite{
    "Charc Suite",
    {
      testCharcEmptyStream,
      testCharcSimpleWordInStream,
      testCharcHelloWorldInStream,
      testCharcMultipleLinesInStream,
    }
  };
  return charcSuite;
}

TEST(testAllcharcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, allcharc(input));
}

TEST(testAllcharcSimpleWordInStream) {
  std::istringstream input{"Counting"};
  ASSERT_EQUAL(8, allcharc(input));
}

TEST(testAllcharcHelloWorldInStream) {
  std::istringstream input{"Hello, world!"};
  ASSERT_EQUAL(13, allcharc(input));
}

TEST(testAllcharcMultipleLinesInStream) {
  std::istringstream input{"Counting some characters\nin my stream\n "};
  ASSERT_EQUAL(39, allcharc(input));
}

TEST(testAllcharcOnlyWhitespaceInStream) {
  std::istringstream input{" \t\n "};
  ASSERT_EQUAL(4, allcharc(input));
}

auto createAllcharcSuite() -> cute::suite {
  cute::suite allcharcSuite{
    "Allcharc Suite",
    {
      testAllcharcEmptyStream,
      testAllcharcSimpleWordInStream,
      testAllcharcHelloWorldInStream,
      testAllcharcMultipleLinesInStream,
      testAllcharcOnlyWhitespaceInStream,
    }
  };
  return allcharcSuite;
}


TEST(testWcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, wc(input));
}

TEST(testWcSimpleWordInStream) {
  std::istringstream input{"Counting"};
  ASSERT_EQUAL(1, wc(input));
}

TEST(testWcHelloWorldInStream) {
  std::istringstream input{"Hello, World! \n"};
  ASSERT_EQUAL(2, wc(input));
}

TEST(testWcMultipleLinesInStream) {
  std::istringstream input{"Hi there \nI think\n I should\n write a test\n \nfirst"};
  ASSERT_EQUAL(10, wc(input));
}

auto createWcSuite() -> cute::suite {
  cute::suite wcSuite{
    "Wc Suite",
    {
      testWcEmptyStream,
      testWcSimpleWordInStream,
      testWcHelloWorldInStream,
      testWcMultipleLinesInStream,
    }
  };
  return wcSuite;
}


TEST(testLcEmptyStream) {
  std::istringstream input{""};
  ASSERT_EQUAL(0, lc(input));
}

TEST(testLcSimpleWordInStream) {
  std::istringstream input{"Counting"};
  ASSERT_EQUAL(0, lc(input));
}

TEST(testLcTrailingLinebreakInStream) {
  std::istringstream input{"Hello, World! \n"};
  ASSERT_EQUAL(1, lc(input));
}

TEST(testLcFiveEmptyLinesInStream) {
  std::istringstream input{"\n\n\n\n\n"};
  ASSERT_EQUAL(5, lc(input));
}

auto createSumiSuite() -> cute::suite {
  cute::suite lcSuite{
    "Lc Suite",
    {
      testLcEmptyStream,
      testLcSimpleWordInStream,
      testLcTrailingLinebreakInStream,
      testLcFiveEmptyLinesInStream,
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