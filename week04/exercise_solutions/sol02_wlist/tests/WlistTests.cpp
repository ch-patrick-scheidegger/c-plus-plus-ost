#include "Wlist.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testWlistEmptyInput) {
  std::istringstream input{""};
  std::ostringstream output{};
  wlist(input, output);
  ASSERT_EQUAL("", output.str());
}

TEST(testWlistSingleWordInput) {
  std::istringstream input{"Word"};
  std::ostringstream output{};
  wlist(input, output);
  ASSERT_EQUAL("Word\n", output.str());
}

TEST(testWlistTwoWordsDifferentCaseInput) {
  std::istringstream input{"Word word"};
  std::ostringstream output{};
  wlist(input, output);
  ASSERT_EQUAL("Word\nword\n", output.str());
}

TEST(testWlistSentenceInput) {
  std::istringstream input{"How much wood would a woodchuck chuck if a woodchuck could chuck wood"};
  std::ostringstream output{};
  wlist(input, output);
  ASSERT_EQUAL("How\na\nchuck\ncould\nif\nmuch\nwood\nwoodchuck\nwould\n", output.str());
}

TEST(testWlistMixedLettersAndDigitsInput) {
  std::istringstream input{"Order 5 pizzas!\norder 3 Pizzas!"};
  std::ostringstream output{};
  wlist(input, output);
  ASSERT_EQUAL("3\n5\nOrder\nPizzas!\norder\npizzas!\n", output.str());
}



auto createPrintFunctionTableSuite() -> cute::suite {
  cute::suite wlistSuite{
    "Wlist Suite",
    {
      testWlistEmptyInput,
      testWlistSingleWordInput,
      testWlistTwoWordsDifferentCaseInput,
      testWlistSentenceInput,
      testWlistMixedLettersAndDigitsInput,
    }
  };
  return wlistSuite;
}


TEST(testWlistCaselessEmptyInput) {
  std::istringstream input{""};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("", output.str());
}

TEST(testWlistCaselessSingleWordInput) {
  std::istringstream input{"Word"};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("Word\n", output.str());
}

TEST(testWlistCaselessTwoWordsDifferentCaseInput) {
  std::istringstream input{"Word word"};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("Word\n", output.str());
}

TEST(testWlistCaselessSentenceInput) {
  std::istringstream input{"How much wood would a woodchuck chuck if a woodchuck could chuck wood"};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("a\nchuck\ncould\nHow\nif\nmuch\nwood\nwoodchuck\nwould\n", output.str());
}

TEST(testWlistCaselessMixedLettersAndDigitsInput) {
  std::istringstream input{"Order 5 pizzas!\norder 3 Pizzas!"};
  std::ostringstream output{};
  wlist_caseless(input, output);
  ASSERT_EQUAL("3\n5\nOrder\npizzas!\n", output.str());
}

auto createWlistCaselessSuite() -> cute::suite {
  cute::suite wlistCaselessSuite{
    "Wlist Caseless Suite",
    {
      testWlistCaselessEmptyInput,
      testWlistCaselessSingleWordInput,
      testWlistCaselessTwoWordsDifferentCaseInput,
      testWlistCaselessSentenceInput,
      testWlistCaselessMixedLettersAndDigitsInput,
    }
  };
  return wlistCaselessSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createPrintFunctionTableSuite());
  suiteResult &= runner(createWlistCaselessSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}