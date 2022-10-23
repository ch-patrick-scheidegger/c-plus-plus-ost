#include "Date.hpp"
#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <cute/xml_listener.h>
#include <sstream>
#include <stdexcept>
#include <string>


using namespace calendar;

TEST(testPrintADate) {
	std::ostringstream os{};
	Date const day { 2012, 8, 20 };
	os << day;
	ASSERT_EQUAL("20.08.2012", os.str());
}

TEST(testPrintADateDoesntChangeFillChar) {
	std::ostringstream os{};
	Date const day { 2012, 8, 20 };
	auto ch = os.fill();
	os << day;
	ASSERT_EQUAL(ch, os.fill());
}

TEST(testIsValidYearLowerBoundary) {
	ASSERT(Date::isValidYear(1813));
	ASSERT(!Date::isValidYear(1812));
}
TEST(testIsValidYearUpperBoundary) {
	ASSERT(Date::isValidYear(9999));
	ASSERT(!Date::isValidYear(10000));
}

TEST(testIsLeapYear) {
	ASSERT(Date::isLeapYear(1964));
	ASSERT(Date::isLeapYear(2000));
	ASSERT(Date::isLeapYear(2400));
	ASSERT(Date::isLeapYear(2012));
	ASSERT(!Date::isLeapYear(1900));
	ASSERT(!Date::isLeapYear(2013));
	ASSERT(!Date::isLeapYear(2100));
}

TEST(testIsValidDateValid) {
	ASSERT(Date::isValidDate(2012, Date::Aug, 20));
	ASSERT(Date::isValidDate(2012, Date::Feb, 29));
	ASSERT(Date::isValidDate(2000, Date::Feb, 29));
	ASSERT(Date::isValidDate(2011, Date::Dec, 31));
}
TEST(testIsValidDateInValid) {
	ASSERT(!Date::isValidDate(2012, Date::Jun, 31));
	ASSERT(!Date::isValidDate(2011, Date::Feb, 29));
	ASSERT(!Date::isValidDate(1900, Date::Feb, 29));
	ASSERT(!Date::isValidDate(2011, static_cast<Date::Month>(0), 31));
}

TEST(testDateCtorThrowsIfInvalid) {
	ASSERT_THROWS((Date { 2012, 6, 31 }), std::out_of_range);
	ASSERT_THROWS((Date { 0, 0, 0 }), std::out_of_range);
	ASSERT_THROWS((Date { 1900, 2, 29 }), std::out_of_range);
	ASSERT_THROWS((Date { 2011, 0, 31 }), std::out_of_range);
}

struct NextDayData {
	Date today;
	Date expected;
	cute::test_failure fail;
} const nextDayEntries[] {
		{Date{2012, 8, 20}, Date{2012, 8, 21}, DDT()},
		{Date{2012, 8, 31}, Date{2012, 9, 1}, DDT()},
		{Date{2012, 9, 30}, Date{2012, 10, 1}, DDT()},
		{Date{2012, 2, 29}, Date{2012, 3, 1}, DDT()},
		{Date{2013, 2, 28}, Date{2013, 3, 1}, DDT()},
		{Date{2012, 2, 28}, Date{2012, 2, 29}, DDT()},
		{Date{2012, 12, 31}, Date{2013, 1, 1}, DDT()}
};

TEST(testNextDay) {
	for (auto entry : nextDayEntries) {
		std::cout << "testing tomorrow of " << entry.today << std::endl;
		Date const tomorrow = entry.today.nextDay();
		ASSERT_EQUAL_DDT(entry.expected, tomorrow, entry.fail);
	}
}

TEST(testNextDayEndOfLastAllowedYear) {
	Date const lastdayever { 9999, 12, 31 };
	ASSERT_THROWS(lastdayever.nextDay(), std::out_of_range);
}

TEST(testDateBuildIn) {
	Date aday { 2012, 8, 10 };
	Date bday = aday;
	ASSERT_EQUAL(aday, bday);
	Date cday { 2000, 1, 1 };
	aday = cday;
	ASSERT_EQUAL(aday, cday);
}

TEST(testDateLessThanAdjacentDates) {
	Date aday { 2012, 8, 13 };
	Date later { 2012, 8, 14 };
	ASSERT(aday < later);
	ASSERT(!(later < aday)); // asymmetric
	ASSERT(!(aday < aday)); // not reflexive
}

TEST(testDateLessThanYearOff) {
	Date aday { 2011, 8, 13 };
	Date yearlater { 2012, 8, 13 };
	ASSERT(aday < yearlater);
	ASSERT(!(yearlater < aday));
}

TEST(testDateLessThanMonthOff) {
	Date aday { 2012, 7, 13 };
	Date later { 2012, 8, 13 };
	ASSERT(aday < later);
	ASSERT(!(later < aday));
}

TEST(testDateGreaterThan) {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(later > aday);
	ASSERT(!(aday > later));
}

TEST(testDateGreaterThanOrEqual) {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(later >= aday);
	ASSERT(aday >= aday);
	ASSERT(!(aday >= later));
}

TEST(testDateLessThanOrEqual) {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(aday <= aday);
	ASSERT(aday <= later);
	ASSERT(!(later <= aday));
}

TEST(testDateEqual) {
	Date aday { 2012, 7, 29 };
	ASSERT(aday == aday);
	ASSERT(aday == (Date { 2012, 7, 29 }));
	ASSERT(!(aday == Date { 2012, 7, 28 }));
}

TEST(testDateInEqual) {
	Date aday { 2012, 7, 29 };
	ASSERT(!(aday != aday));
	ASSERT(aday != (Date { 2012, 7, 28 }));
}

TEST(testDateReadValidDates) {
	std::istringstream is { "17.08.2012 18/8/2012 19-08-2012" };
	Date aday { 2000, 1, 1 };
	Date expect { 2012, 8, 17 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL(expect, aday);
	expect = expect.nextDay();
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL(expect, aday);
	expect = expect.nextDay();
	is >> aday;
	ASSERT(is.eof());
	ASSERT_EQUAL(expect, aday);
}

TEST(testDateReadShortYear) {
	std::istringstream is { "17.08.12 1-9-13" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 17 }), aday);
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2013, 9, 1 }), aday);
}
TEST(testDateReadInvalidYear) {
	std::istringstream is { "1-1-100" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(is.fail());
	ASSERT(is.eof());
}

TEST(testDateReadYYYYMMDD) {
	std::istringstream is { "2012-08-20" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 20 }), aday);
}

TEST(testDateReadInValidDates) {
	std::istringstream is { "1-1-100 a.b.2000 1:1:11" };
	Date aday { 2000, 1, 1 };
	Date const expect = aday;
	is >> aday;
	ASSERT(is.fail());
	is.clear();
	ASSERT_EQUAL(expect, aday);
	is >> aday;
	ASSERT(is.fail());
	is.clear();
	std::string dummy;
	is >> dummy; // skip up tp ws
	is >> aday;
	ASSERT(is.fail());
	ASSERT(is.eof());
}

TEST(testMakeDateYYYYMMDD) {
	std::istringstream is { "2012-08-20" };
	Date aday = makeDate(is);
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 20 }), aday);
	ASSERT_EQUAL((Date { 9999, 12, 31 }), makeDate(is));
}

TEST(testInputOperatorDateButLessThan) {
	std::istringstream is { "2012-08-20" };
	Date aday { 2001, 1, 26 };
	//is > aday; // compiles without explicit
}

TEST(testCreateDatesWithMonthEnum) {
	Date const expected{2003, 1, 15};
	ASSERT_EQUAL(expected, (Date{15, Date::Jan, 2003}));
	ASSERT_EQUAL(expected, (Date{Date::Jan, 15, 2003}));
}

struct DayOfWeekData {
	Date date;
	Date::DayOfWeek expected;
	cute::test_failure fail;
} const dayOfWeekCases[] {
		{Date{21, Date::Oct, 2019}, Date::Monday, DDT()},
		{Date{22, Date::Oct, 2019}, Date::Tuesday, DDT()},
		{Date{23, Date::Oct, 2019}, Date::Wednesday, DDT()},
		{Date{24, Date::Oct, 2019}, Date::Thursday, DDT()},
		{Date{25, Date::Oct, 2019}, Date::Friday, DDT()},
		{Date{26, Date::Oct, 2019}, Date::Saturday, DDT()},
		{Date{27, Date::Oct, 2019}, Date::Sunday, DDT()},
		{Date{1, Date::Jan, 1980}, Date::Tuesday, DDT()}
};

TEST(testDayOfWeek) {
	for (auto entry : dayOfWeekCases) {
		auto const actual = entry.date.dayOfWeek();
		ASSERT_EQUAL_DDT(entry.expected, actual, entry.fail);
	}
}

auto createDateSuite() -> cute::suite {
  return cute::suite {
    "Date with Enum Suite",
	{
		testPrintADate, 
		testPrintADateDoesntChangeFillChar,
		testIsValidYearLowerBoundary, 
		testIsValidYearUpperBoundary,
		testIsLeapYear, 
		testIsValidDateValid, 
		testIsValidDateInValid,
		testDateCtorThrowsIfInvalid, 
		testNextDay,
		testNextDayEndOfLastAllowedYear, 
		testDateBuildIn,
		testDateLessThanAdjacentDates, 
		testDateLessThanYearOff,
		testDateLessThanMonthOff, 
		testDateGreaterThan,
		testDateGreaterThanOrEqual, 
		testDateLessThanOrEqual, 
		testDateEqual,
		testDateInEqual, 
		testDateReadValidDates, 
		testDateReadShortYear,
		testDateReadInvalidYear, 
		testDateReadYYYYMMDD,
		testDateReadInValidDates, 
		testMakeDateYYYYMMDD,
    testInputOperatorDateButLessThan,
    testCreateDatesWithMonthEnum,
    testDayOfWeek,
    }
  };
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createDateSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}