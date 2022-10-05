#include "CountingToLower.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>


TEST(testLowerNone) {
	std::string str("no uppercase characters here");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("no uppercase characters here", str);
}

TEST(testLowerSeveralCharacters) {
	std::string str("Hello World, its ME!");
	ASSERT_EQUAL(4, countingToLower(str));
	ASSERT_EQUAL("hello world, its me!", str);
}

TEST(testLowerAll) {
	std::string str("LOL");
	ASSERT_EQUAL(3, countingToLower(str));
	ASSERT_EQUAL("lol", str);
}

TEST(testLowerEmpty) {
	std::string str("");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("", str);
}


TEST(testUmlautsAreNotChanged) {
	std::string str("ÄÖÜ");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("ÄÖÜ", str);
}


auto createCountingToLowerSuite() -> cute::suite {
  cute::suite countingToLowerSuite{
    "CountingToLower Suite",
    {
      testLowerNone,
      testLowerSeveralCharacters,
      testLowerAll,
      testLowerEmpty,
      testUmlautsAreNotChanged,
    }
  };
  return countingToLowerSuite;
}


auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createCountingToLowerSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}