#include "Sevensegment.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(testLargeDigitZero) {
  std::ostringstream output{};
  printLargeDigit(0, output);
  ASSERT_EQUAL(" - \n"
               "| |\n"
               "   \n"
               "| |\n"
               " - \n", output.str());
}

auto createPrintLargeDigitSuite() -> cute::suite {
  cute::suite largeDigitSuite{
    "Print Large Digit Suite",
    {
      testLargeDigitZero,
    }
  };
  return largeDigitSuite;
}



auto createPrintLargeNumberSuite() -> cute::suite {
  cute::suite largeNumberSuite{
    "Print Large Number Suite",
    {
    }
  };
  return largeNumberSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createPrintLargeDigitSuite());
  suiteResult &= runner(createPrintLargeNumberSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}