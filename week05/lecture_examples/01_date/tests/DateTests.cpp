#include "Date.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>
#include <utility>

TEST(testDefaultCreateDate) {
  Date defaultDate{};
  Date sameDate{1980, 1, 1};
  ASSERT(defaultDate == sameDate);
}

TEST(testInequalDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(someDay != tomorrow);
}

TEST(testLessThanDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(someDay < tomorrow);
}

TEST(testGreaterThanDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(tomorrow > someDay);
}

TEST(testLessThanEqualDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(someDay <= tomorrow);
}

TEST(testGreaterThanEqualDate) {
  Date someDay{2003, 3, 21};
  Date tomorrow{2003, 3, 22};
  ASSERT(tomorrow > someDay);
}

TEST(testPrintDate) {
  std::ostringstream os{};
  Date const day{2012, 8, 20};
  day.print(os);
  ASSERT_EQUAL("20/8/2012", os.str());
}

TEST(testIsLeapYearForLeapYears) {
  auto leaps = {1964, 2000, 2400, 2020};
  ASSERT(std::ranges::all_of(leaps, Date::isLeapYear));
}

TEST(testIsLeapYearForNonLeapYears) {
  auto nonleaps = {1900, 2019, 2100};
  ASSERT(std::ranges::none_of(nonleaps, Date::isLeapYear));
}


TEST(testDateCtorThrowsIfInvalid) {
  using ymdTuple = std::tuple<int, int, int>;
  std::vector<ymdTuple> invalidDates{
      {2012, 6, 31}, {0, 0, 0}, {1900, 2, 29}, {2011, 0, 31}};
  for (auto inputDate : invalidDates) {
    auto const [y, m, d] = inputDate;
    using std::to_string;
    auto const msg = "expecting Date(" + to_string(y) + "," + to_string(m) +
                     "," + to_string(d) + ") to throw";
    ASSERT_THROWSM(msg, (Date{y, m, d}), std::out_of_range);
  }
}

TEST(testTomorrow) {
  using TestData = std::pair<Date, Date>;
  std::vector<TestData> cases{
    {{ 2012, 8, 20 }, { 2012, 8, 21 }},
    {{ 2012, 8, 31 }, { 2012, 9, 1 }},
    {{ 2012, 9, 30 }, { 2012, 10, 1 }},
    {{ 2012, 2, 29 }, { 2012, 3, 1 }},
    {{ 2013, 2, 28 }, { 2013, 3, 1 }},
    {{ 2012, 2, 28 }, { 2012, 2, 29 }},
    {{ 2012, 12, 31 }, { 2013, 1, 1 }},
  };
  for (auto inputCase : cases) {
    auto [input, expected] = inputCase;
    std::ostringstream msg{};
    auto actual = input.tomorrow();
    msg << "Tomorrow of " << input << " should be " << expected << " but was " << actual;
    ASSERT_EQUALM(msg.str(), expected, actual);
  }
}

TEST(testDateReadValidDates) {
	std::istringstream is { "17.08.2012 17/8/2012 17-08-2012" };
	Date aday { 2000, 1, 1 };
	Date expect { 2012, 8, 17 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL(expect, aday);
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL(expect, aday);
	is >> aday;
	ASSERT(is.eof());
	ASSERT_EQUAL(expect, aday);
}

auto createDateSuite() -> cute::suite {
  cute::suite dateSuite{
    "Date Suite",
    {
      testDefaultCreateDate,
      testInequalDate,
      testLessThanDate,
      testGreaterThanDate,
      testLessThanEqualDate,
      testGreaterThanEqualDate,
      testPrintDate,
      testIsLeapYearForLeapYears,
      testIsLeapYearForNonLeapYears,
      testDateCtorThrowsIfInvalid,
      testTomorrow,
      testDateReadValidDates,
    }
  };
  return dateSuite;
}


auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createDateSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}