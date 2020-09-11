#include "Date.h"

#include <array>
#include <stdexcept>
#include <ostream>
#include <istream>
#include <iomanip>
#include <iterator>
#include <algorithm>

namespace calendar {

std::ostream& operator<<(std::ostream &out, Date const &date) {
	auto const previousFillChar = out.fill('0');
	out << std::setw(2) << date.day << '.';
	out << std::setw(2) << date.month << '.';
	out << std::setw(4) << date.year;
	out.fill(previousFillChar);
	return out;
}

bool Date::isValidYear(int year) {
	return year >= 1813 && year < 10000;
}

bool Date::isLeapYear(int year) {
	return !(year % 4) && ((year % 100) || !(year % 400));
}

bool Date::isValidDate(int year, int month, int day) {
	return isValidYear(year) && month > 0 && month < 13 && day > 0 && day <= endOfMonth(year, month);
}

Date::Date(int year, int month, int day) :
		year { year }, month { month }, day { day } {
	if (!isValidDate(year, month, day)) {
		throw std::out_of_range { "invalid date" };
	}
}

Date::Date() :
		year { 9999 }, month { 12 }, day { 31 } {
}

int Date::endOfMonth(int year, int month) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return (isLeapYear(year) ? 29 : 28);
	}
	throw std::invalid_argument { "invalid month" };
}

Date Date::nextDay() const {
	auto tomorrowDay = (day == endOfMonth(year, month)) ? 1 : day + 1;
	auto tomorrowMonth = month;
	auto tomorrowYear = year;
	if (tomorrowDay == 1) {
		tomorrowMonth = (month == 12) ? 1 : month + 1;
		if (tomorrowMonth == 1) {
			tomorrowYear++;
		}
	}
	return {tomorrowYear, tomorrowMonth, tomorrowDay};
}

bool Date::operator <(Date const &rhs) const {
	return year < rhs.year || (year == rhs.year && (month < rhs.month || (month == rhs.month && day < rhs.day)));
}

bool Date::operator==(Date const & rhs) const {
	return year == rhs.year && month == rhs.month && day == rhs.day;
}

std::array<char, 3> const validSeparators{'.', '/', '-'};

bool Date::isValidSeparator(char separator) {
	return std::find(cbegin(validSeparators), cend(validSeparators), separator) != cend(validSeparators);
}

std::istream & operator>>(std::istream & in, Date & date) {
	int inDay { }, inMonth { }, inYear { };
	char sep1 { }, sep2 { };
	in >> inDay >> sep1 >> inMonth >> sep2 >> inYear;
	if (Date::isValidYear(inDay)) {
		std::swap(inDay, inYear);
	}
	if (inYear >= 0 && inYear < 100) {
		inYear += 2000;
	}
	if (!in.fail() && Date::isValidSeparator(sep1) && sep1 == sep2 && Date::isValidDate(inYear, inMonth, inDay)) {
		date = Date{inYear, inMonth, inDay};
	} else {
		in.setstate(std::ios::failbit);
	}
	return in;
}

Date::Date(std::istream &in) :
		year { }, month { }, day { } {
	in >> *this;
	if (in.fail()) {
		throw std::out_of_range { "invalid date" };
	}
}

Date makeDate(std::istream &in)
try {
	return Date { in };
}
catch (std::out_of_range const&) {
	return Date { };// default value
}


} // namespace calendar
