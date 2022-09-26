#include "Tables.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(testFractabSize1) {
  std::istringstream input{"1"};
  std::ostringstream output{};
  std::string expected{
    "Enter limit (max 10):\n"
    "       0       1\n"
    "       1       1\n"
  };
  fractab(input, output);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testFractabSize2) {
  std::istringstream input{"2"};
  std::ostringstream output{};
  std::string expected{
    "Enter limit (max 10):\n"
    "       0       1       2\n"
    "       1       1     0.5\n"
    "       2       2       1\n"
  };
  fractab(input, output);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testFractabSize30) {
  std::istringstream input{"10"};
  std::ostringstream output{};
  std::string expected{
    "Enter limit (max 10):\n"
    "       0       1       2       3       4       5       6       7       8       9      10\n"
    "       1       1     0.5 0.33333    0.25     0.2 0.16667 0.14286   0.125 0.11111     0.1\n"
    "       2       2       1 0.66667     0.5     0.4 0.33333 0.28571    0.25 0.22222     0.2\n"
    "       3       3     1.5       1    0.75     0.6     0.5 0.42857   0.375 0.33333     0.3\n"
    "       4       4       2  1.3333       1     0.8 0.66667 0.57143     0.5 0.44444     0.4\n"
    "       5       5     2.5  1.6667    1.25       1 0.83333 0.71429   0.625 0.55556     0.5\n"
    "       6       6       3       2     1.5     1.2       1 0.85714    0.75 0.66667     0.6\n"
    "       7       7     3.5  2.3333    1.75     1.4  1.1667       1   0.875 0.77778     0.7\n"
    "       8       8       4  2.6667       2     1.6  1.3333  1.1429       1 0.88889     0.8\n"
    "       9       9     4.5       3    2.25     1.8     1.5  1.2857   1.125       1     0.9\n"
    "      10      10       5  3.3333     2.5       2  1.6667  1.4286    1.25  1.1111       1\n"
  };
  fractab(input, output);
  ASSERT_EQUAL(expected, output.str());
}


auto createFractabSuite() -> cute::suite {
  cute::suite fractabSuite{
    "Fractab Suite",
    {
      // testFractabSize1,
      // testFractabSize2,
      // testFractabSize30,
    }
  };
  return fractabSuite;
}


auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createFractabSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}