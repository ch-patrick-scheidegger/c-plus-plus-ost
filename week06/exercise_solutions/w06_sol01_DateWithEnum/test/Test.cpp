#include "Date.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <sstream>
#include <stdexcept>
#include <string>

using namespace calendar;

void testPrintADate() {
	std::ostringstream os{};
	Date const day { 2012, 8, 20 };
	os << day;
	ASSERT_EQUAL("20.08.2012", os.str());
}

void testPrintADateDoesntChangeFillChar() {
	std::ostringstream os{};
	Date const day { 2012, 8, 20 };
	auto ch = os.fill();
	os << day;
	ASSERT_EQUAL(ch, os.fill());
}

void testIsValidYearLowerBoundary() {
	ASSERT(Date::isValidYear(1813));
	ASSERT(!Date::isValidYear(1812));
}
void testIsValidYearUpperBoundary() {
	ASSERT(Date::isValidYear(9999));
	ASSERT(!Date::isValidYear(10000));
}

void testIsLeapYear() {
	ASSERT(Date::isLeapYear(1964));
	ASSERT(Date::isLeapYear(2000));
	ASSERT(Date::isLeapYear(2400));
	ASSERT(Date::isLeapYear(2012));
	ASSERT(!Date::isLeapYear(1900));
	ASSERT(!Date::isLeapYear(2013));
	ASSERT(!Date::isLeapYear(2100));
}

void testIsValidDateValid() {
	ASSERT(Date::isValidDate(2012, Date::Aug, 20));
	ASSERT(Date::isValidDate(2012, Date::Feb, 29));
	ASSERT(Date::isValidDate(2000, Date::Feb, 29));
	ASSERT(Date::isValidDate(2011, Date::Dec, 31));
}
void testIsValidDateInValid() {
	ASSERT(!Date::isValidDate(2012, Date::Jun, 31));
	ASSERT(!Date::isValidDate(2011, Date::Feb, 29));
	ASSERT(!Date::isValidDate(1900, Date::Feb, 29));
	ASSERT(!Date::isValidDate(2011, static_cast<Date::Month>(0), 31));
}

void testDateCtorThrowsIfInvalid() {
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

void testNextDay() {
	for (auto entry : nextDayEntries) {
		std::cout << "testing tomorrow of " << entry.today << std::endl;
		Date const tomorrow = entry.today.nextDay();
		ASSERT_EQUAL_DDT(entry.expected, tomorrow, entry.fail);
	}
}

void testNextDayEndOfLastAllowedYear() {
	Date const lastdayever { 9999, 12, 31 };
	ASSERT_THROWS(lastdayever.nextDay(), std::out_of_range);
}

void testDateBuildIn() {
	Date aday { 2012, 8, 10 };
	Date bday = aday;
	ASSERT_EQUAL(aday, bday);
	Date cday { 2000, 1, 1 };
	aday = cday;
	ASSERT_EQUAL(aday, cday);
}

void testDateLessThanAdjacentDates() {
	Date aday { 2012, 8, 13 };
	Date later { 2012, 8, 14 };
	ASSERT(aday < later);
	ASSERT(!(later < aday)); // asymmetric
	ASSERT(!(aday < aday)); // not reflexive
}

void testDateLessThanYearOff() {
	Date aday { 2011, 8, 13 };
	Date yearlater { 2012, 8, 13 };
	ASSERT(aday < yearlater);
	ASSERT(!(yearlater < aday));
}

void testDateLessThanMonthOff() {
	Date aday { 2012, 7, 13 };
	Date later { 2012, 8, 13 };
	ASSERT(aday < later);
	ASSERT(!(later < aday));
}

void testDateGreaterThan() {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(later > aday);
	ASSERT(!(aday > later));
}

void testDateGreaterThanOrEqual() {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(later >= aday);
	ASSERT(aday >= aday);
	ASSERT(!(aday >= later));
}

void testDateLessThanOrEqual() {
	Date aday { 2012, 2, 29 };
	Date later { 2012, 3, 1 };
	ASSERT(aday <= aday);
	ASSERT(aday <= later);
	ASSERT(!(later <= aday));
}

void testDateEqual() {
	Date aday { 2012, 7, 29 };
	ASSERT(aday == aday);
	ASSERT(aday == (Date { 2012, 7, 29 }));
	ASSERT(!(aday == Date { 2012, 7, 28 }));
}

void testDateInEqual() {
	Date aday { 2012, 7, 29 };
	ASSERT(!(aday != aday));
	ASSERT(aday != (Date { 2012, 7, 28 }));
}

void testDateReadValidDates() {
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

void testDateReadShortYear() {
	std::istringstream is { "17.08.12 1-9-13" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 17 }), aday);
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2013, 9, 1 }), aday);
}
void testDateReadInvalidYear() {
	std::istringstream is { "1-1-100" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(is.fail());
	ASSERT(is.eof());
}

void testDateReadYYYYMMDD() {
	std::istringstream is { "2012-08-20" };
	Date aday { 2000, 1, 1 };
	is >> aday;
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 20 }), aday);
}

void testDateReadInValidDates() {
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

void testMakeDateYYYYMMDD() {
	std::istringstream is { "2012-08-20" };
	Date aday = makeDate(is);
	ASSERT(!is.fail());
	ASSERT_EQUAL((Date { 2012, 8, 20 }), aday);
	ASSERT_EQUAL((Date { 9999, 12, 31 }), makeDate(is));
}

void testInputOperatorDateButLessThan() {
	std::istringstream is { "2012-08-20" };
	Date aday { 2001, 1, 26 };
	//is > aday; // compiles without explicit
}

void testCreateDatesWithMonthEnum() {
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

void testDayOfWeek() {
	for (auto entry : dayOfWeekCases) {
		auto const actual = entry.date.dayOfWeek();
		ASSERT_EQUAL_DDT(entry.expected, actual, entry.fail);
	}
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	s.push_back(CUTE(testPrintADate));
	s.push_back(CUTE(testPrintADateDoesntChangeFillChar));
	s.push_back(CUTE(testIsValidYearLowerBoundary));
	s.push_back(CUTE(testIsValidYearUpperBoundary));
	s.push_back(CUTE(testIsLeapYear));
	s.push_back(CUTE(testIsValidDateValid));
	s.push_back(CUTE(testIsValidDateInValid));
	s.push_back(CUTE(testDateCtorThrowsIfInvalid));
	s.push_back(CUTE(testNextDay));
	s.push_back(CUTE(testNextDayEndOfLastAllowedYear));
	s.push_back(CUTE(testDateBuildIn));
	s.push_back(CUTE(testDateLessThanAdjacentDates));
	s.push_back(CUTE(testDateLessThanYearOff));
	s.push_back(CUTE(testDateLessThanMonthOff));
	s.push_back(CUTE(testDateGreaterThan));
	s.push_back(CUTE(testDateGreaterThanOrEqual));
	s.push_back(CUTE(testDateLessThanOrEqual));
	s.push_back(CUTE(testDateEqual));
	s.push_back(CUTE(testDateInEqual));
	s.push_back(CUTE(testDateReadValidDates));
	s.push_back(CUTE(testDateReadShortYear));
	s.push_back(CUTE(testDateReadInvalidYear));
	s.push_back(CUTE(testDateReadYYYYMMDD));
	s.push_back(CUTE(testDateReadInValidDates));
	s.push_back(CUTE(testMakeDateYYYYMMDD));
	s.push_back(CUTE(testCreateDatesWithMonthEnum));
	s.push_back(CUTE(testDayOfWeek));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

