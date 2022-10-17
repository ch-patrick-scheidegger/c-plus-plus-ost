#include "Date.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testDefaultCreateDate) {
  Date defaultDate{};
  Date sameDate{1980, 1, 1};
  ASSERT(defaultDate == sameDate);
}

TEST(testLessThanDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  // ASSERT(someDay < tomorrow);
}

TEST(testInequalDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(someDay != tomorrow);
}

auto createDateCtorSuite() -> cute::suite {
  cute::suite dateCtor{
    "Date Constructor Suite",
    {
      testDefaultCreateDate,
      testLessThanDate,
      testInequalDate
    }
  };
  return dateCtor;
}


auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createDateCtorSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}