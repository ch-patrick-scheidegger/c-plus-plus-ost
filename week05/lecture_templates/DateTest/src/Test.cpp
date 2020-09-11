#include "Date.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <algorithm>

#include <iterator>
#include <sstream>
#include <stdexcept>
#include <tuple>
#include <array>

void testPrintADate() {
	std::ostringstream os { };
	Date const day { 2012, 8, 20 };
	day.print(os);
	ASSERT_EQUAL("20.08.2012", os.str());
}

void testPrintADateDoesntChangeFillChar() {
	std::ostringstream os { };
	Date const day { 2012, 8, 20 };
	auto ch = os.fill();
	day.print(os);
	ASSERT_EQUAL(ch, os.fill());
}

void testIsValidYearLowerBoundaryAbove() {
	ASSERT(Date::isValidYear(1813));
}
void testIsValidYearLowerBoundaryBelow() {
	ASSERT(!Date::isValidYear(1812));
}
void testIsValidYearUpperBoundaryBelow() {
	ASSERT(Date::isValidYear(9999));
}
void testIsValidYearUpperBoundaryAbove() {
	ASSERT(!Date::isValidYear(10000));
}

void testIsLeapYearForLeapYears() {
	auto leaps = {1964,2000,2400,2020};
	ASSERT(std::all_of(std::begin(leaps),
					   std::end(leaps),&Date::isLeapYear));
}
void testIsLeapYearForNonLeapYears() {
	auto nonleaps = {1900, 2019, 2100 };
	ASSERT(std::none_of(std::begin(nonleaps),
				   std::end(nonleaps),&Date::isLeapYear));
}

using datedata = std::tuple<int,int,int>;

void testIsValidDateValid() {	
	std::array<datedata const, 4> dates {{
		{ 2020, 8, 20 },
		{ 2020, 2, 29 },
		{ 2000, 2, 29 },
		{ 2019, 12, 31 }} };
	ASSERT(std::all_of(std::begin(dates), std::end(dates),
			[](datedata t){return std::apply(Date::isValidDate,t);}));
}
void testIsValidDateInValid() {
	std::array<datedata const, 4> dates {{
		{ 2020, 6, 31 },
		{ 2019, 2, 29 },
		{ 1900, 2, 29 },
		{ 2019, 0, 31 }} };
	ASSERT(std::none_of(std::begin(dates), std::end(dates),
			[](datedata t){return std::apply(Date::isValidDate,t);}));
}

void testDateCtorThrowsIfInvalid() {
	std::array<datedata const, 4> invaliddates = {{
			{2012,6,31},
			{ 0, 0, 0 },
			{ 1900, 2, 29 },
			{ 2011, 0, 31 }}};
	for(datedata const t:invaliddates){
		auto const [y,m,d] = t;
		using std::to_string;
		auto const msg = "expecting Date("+to_string(y)+","+to_string(m)+","+to_string(d)+") to throw";
		ASSERT_THROWSM(msg,(Date { y, m, d }), std::out_of_range);
	}
}

bool datesAreEqual(Date const &l, Date const &r) {
	std::ostringstream o1;
	r.print(o1);
	std::ostringstream o2;
	r.print(o2);
	return o1.str() == o2.str();
}

void testNextDaySimple() {
	Date aday { 2012, 8, 20 };
	aday.nextDay();
	ASSERT(datesAreEqual(aday, Date { 2012, 8, 21 }));
}

void testNextDayEndOfMonth() {
	Date eom { 2012, 8, 31 };
	eom.nextDay();
	ASSERT(datesAreEqual(eom, Date { 2012, 9, 1 }));
}
void testNextDayEndOfShortMonth() {
	Date eosep { 2012, 9, 30 };
	eosep.nextDay();
	ASSERT(datesAreEqual(eosep, Date { 2012, 10, 1 }));
}
void testNextDayEndOfFeburary() {
	Date eofeb { 2012, 2, 29 };
	eofeb.nextDay();
	ASSERT(datesAreEqual(eofeb, Date { 2012, 3, 1 }));
}
void testNextDayEndOfFeburaryNonLeapYear() {
	Date eofeb { 2013, 2, 28 };
	eofeb.nextDay();
	ASSERT(datesAreEqual(eofeb, Date { 2013, 3, 1 }));
}
void testNextDayNotEndOfFeburaryInLeapYear() {
	Date aday { 2012, 2, 28 };
	aday.nextDay();
	ASSERT(datesAreEqual(aday, Date { 2012, 2, 29 }));
}

void testNextDayEndOfYear() {
	Date silvester { 2012, 12, 31 };
	silvester.nextDay();
	ASSERT(datesAreEqual(silvester, Date { 2013, 1, 1 }));
}
void testNextDayEndOfLastAllowedYear() {
	Date lastdayever { 9999, 12, 31 };
	ASSERT_THROWS(lastdayever.nextDay(), std::out_of_range);
}

void testDateBuildIn() {
	Date aday { 2012, 8, 10 };
	Date const bday { aday };
	ASSERT(datesAreEqual(aday, bday));
	Date const cday { 2000, 1, 1 };
	aday = cday;
	ASSERT(datesAreEqual(aday, cday));
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
	ASSERT(aday.operator<(yearlater));
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

void testInputShortLimit() {
	std::istringstream is("70000");
	unsigned short x { };
	is >> x;
	ASSERT_EQUAL(0xffffUL, x);
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	s.push_back(CUTE(testPrintADate));
	s.push_back(CUTE(testPrintADateDoesntChangeFillChar));
	s.push_back(CUTE(testIsValidYearUpperBoundaryBelow));
	s.push_back(CUTE(testIsLeapYearForLeapYears));
	s.push_back(CUTE(testIsValidDateValid));
	s.push_back(CUTE(testIsValidDateInValid));
	s.push_back(CUTE(testDateCtorThrowsIfInvalid));
	s.push_back(CUTE(testNextDaySimple));
	s.push_back(CUTE(testNextDayEndOfMonth));
	s.push_back(CUTE(testNextDayEndOfShortMonth));
	s.push_back(CUTE(testNextDayEndOfFeburary));
	s.push_back(CUTE(testNextDayEndOfFeburaryNonLeapYear));
	s.push_back(CUTE(testNextDayNotEndOfFeburaryInLeapYear));
	s.push_back(CUTE(testNextDayEndOfYear));
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
	s.push_back(CUTE(testInputShortLimit));
	s.push_back(CUTE(testIsValidYearLowerBoundaryAbove));
	s.push_back(CUTE(testIsValidYearLowerBoundaryBelow));
	s.push_back(CUTE(testIsValidYearUpperBoundaryAbove));
	s.push_back(CUTE(testIsLeapYearForNonLeapYears));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

