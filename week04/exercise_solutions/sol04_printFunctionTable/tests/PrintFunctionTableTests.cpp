#include "PrintFunctionTable.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>


auto identitiy = [](auto v) {return v;}; 

TEST(testPrintFunctionTableNoSteps) {
  std::string expected = "x    \n"
                         "f(x) \n";
  std::ostringstream output{};
  printFunctionTable(output, 1.0, 2.0, 0, identitiy);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testPrintFunctionTableIdentitiy) {
  std::string expected = "x    1.0 2.0 3.0 \n"
                         "f(x) 1.0 2.0 3.0 \n";
  std::ostringstream output{};
  printFunctionTable(output, 1.0, 3.0, 3, identitiy);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testPrintFunctionTableSingleValue) {
  std::string expected = "x    1.0 \n"
                         "f(x) 1.0 \n";
  std::ostringstream output{};
  printFunctionTable(output, 1.0, 3.0, 1, identitiy);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testPrintFunctionTableSquares) {
  std::string expected = "x    1.0 2.0 3.0 \n"
                         "f(x) 1.0 4.0 9.0 \n";
  std::ostringstream output{};
  printFunctionTable(output, 1.0, 3.0, 3, [](auto value) {return value * value;});
  ASSERT_EQUAL(expected, output.str());
}

TEST(testPrintFunctionTableNegativeRange) {
  std::string expected = "x    -1.0 -2.0 -3.0 \n"
                         "f(x) -1.0 -2.0 -3.0 \n";
  std::ostringstream output{};
  printFunctionTable(output, -1.0, -3.0, 3, identitiy);
  ASSERT_EQUAL(expected, output.str());
}

TEST(testPrintFunctionTableRangeOverZero) {
  std::string expected = "x    2.5 1.1 -0.2 -1.6 -3.0 \n"
                         "f(x) 2.5 1.1 -0.2 -1.6 -3.0 \n";
  std::ostringstream output{};
  printFunctionTable(output, 2.5, -3.0, 5, identitiy);
  ASSERT_EQUAL(expected, output.str());
}


auto createPrintFunctionTableSuite() -> cute::suite {
  cute::suite printFunctionTableSuite{
    "PrintFunctionTable Suite",
    {
      testPrintFunctionTableNoSteps,
      testPrintFunctionTableIdentitiy,
      testPrintFunctionTableSingleValue,
      testPrintFunctionTableSquares,
      testPrintFunctionTableNegativeRange,
      testPrintFunctionTableRangeOverZero,
    }
  };
  return printFunctionTableSuite;
}


auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createPrintFunctionTableSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}