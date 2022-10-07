#include "Pocketcalculator.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(testEmptyStream) {
  std::istringstream input{};
  std::ostringstream output{};
  pocketcalculator(input, output);
  ASSERT_EQUAL("", output.str());
}

auto createPocketcalculatorSuite() -> cute::suite {
  cute::suite pocketcalculatorSuite{
    "Pocketcalculator Suite",
    {
      testEmptyStream,
    }
  };
  return pocketcalculatorSuite;
}



auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createPocketcalculatorSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}