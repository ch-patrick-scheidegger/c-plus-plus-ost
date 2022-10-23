#include "Date.hpp"

#include <array>
#include <stdexcept>
#include <ostream>
#include <istream>
#include <iomanip>
#include <iterator>
#include <algorithm>

namespace calendar {

auto Date::print(std::ostream& out) const -> void {
	auto const previousFillChar = out.fill('0');
	out << std::setw(2) << day << '.';
	out << std::setw(2) << month << '.';
	out << std::setw(4) << year;
	out.fill(previousFillChar);
}

auto operator<<(std::ostream &out, Date const &date) -> std::ostream& {
	date.print(out);
	return out;
}

auto Date::isValidYear(int year) -> bool {
	return year >= 1813 && year < 10000;
}

auto Date::isLeapYear(int year) -> bool {
	return !(year % 4) && ((year % 100) || !(year % 400));
}

auto Date::isValidDate(int year, Month month, int day) -> bool {
	return isValidYear(year) && month > 0 && month < 13 && day > 0 && day <= endOfMonth(year, month);
}

Date::Date(int year, int month, int day) :
		Date{day, static_cast<Month>(month), year} {
}

Date::Date(int day, Month month, int year) : year{year}, month{month}, day{day}{
	if (!isValidDate(year, month, day)) {
		throw std::out_of_range { "invalid date" };
	}
}

Date::Date(Month month, int day, int year) : Date{day, month, year}{}

Date::Date() :
		year { 9999 }, month { Dec }, day { 31 } {
}

auto Date::endOfMonth(int year, Month month) -> int {
	switch (month) {
	case Jan:
	case Mar:
	case May:
	case Jul:
	case Aug:
	case Oct:
	case Dec:
		return 31;
	case Apr:
	case Jun:
	case Sep:
	case Nov:
		return 30;
	case Feb:
		return (isLeapYear(year) ? 29 : 28);
	}
	throw std::invalid_argument { "invalid month" };
}

auto Date::nextDay() const -> Date {
	auto tomorrowDay = (day == endOfMonth(year, month)) ? 1 : day + 1;
	auto tomorrowMonth = month;
	auto tomorrowYear = year;
	if (tomorrowDay == 1) {
		tomorrowMonth = static_cast<Month>((month == Dec) ? Jan : month + 1);
		if (tomorrowMonth == Jan) {
			tomorrowYear++;
		}
	}
	return {tomorrowDay, tomorrowMonth, tomorrowYear};
}

auto Date::dayOfWeek() const -> Date::DayOfWeek {
	static std::array<const int, 12> const t{ 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int y = year;
    int m = month;
    y -= m < 3;
    return static_cast<DayOfWeek>((y + y/4 - y/100 + y/400 + t[m-1] + day +6) % 7);
}

std::array<char, 3> const validSeparators{'.', '/', '-'};

auto Date::isValidSeparator(char separator) -> bool {
	return std::find(cbegin(validSeparators), cend(validSeparators), separator) != cend(validSeparators);
}

auto operator>>(std::istream & in, Date & date) -> std::istream & {
	int inDay { }, inMonth { }, inYear { };
	char sep1 { }, sep2 { };
	in >> inDay >> sep1 >> inMonth >> sep2 >> inYear;
	if (Date::isValidYear(inDay)) {
		std::swap(inDay, inYear);
	}
	if (inYear >= 0 && inYear < 100) {
		inYear += 2000;
	}
	if (!in.fail() && Date::isValidSeparator(sep1) && sep1 == sep2 && Date::isValidDate(inYear, static_cast<Date::Month>(inMonth), inDay)) {
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

auto makeDate(std::istream &in) -> Date
try {
	return Date { in };
}
catch (std::out_of_range const&) {
	return Date { };// default value
}

static std::array<std::string, 7> const dayOfWeekNames {
  "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
};

auto operator <<(std::ostream &out, Date::DayOfWeek dayOfWeek) -> std::ostream& {
	out << dayOfWeekNames.at(dayOfWeek);
	return out;
}

} // namespace calendar
