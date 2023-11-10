#ifndef DATE_HPP_
#define DATE_HPP_

#include <compare>
#include <iosfwd>

namespace calendar {

struct Date {
	enum Month {
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};

	enum DayOfWeek {
		Mon, Monday = Mon,
		Tue, Tuesday = Tue,
		Wed, Wednesday = Wed,
		Thu, Thursday = Thu,
		Fri, Friday = Fri,
		Sat, Saturday = Sat,
		Sun, Sunday = Sun
	};

	Date();
	explicit Date(std::istream &in);
	Date(int year, int month, int day);
	Date(int day, Month month, int year);
	Date(Month month, int day, int year);

	auto nextDay() const -> Date;
	auto dayOfWeek() const -> DayOfWeek;
	auto print(std::ostream& out) const -> void;

	auto operator <=>(Date const &rhs) const = default;
	
	static auto isValidYear(int year) -> bool;
	static auto isLeapYear(int year) -> bool;
	static auto isValidDate(int year, Month month, int day) -> bool;
	static auto isValidSeparator(char ch) -> bool;
	static auto endOfMonth(int year, Month month) -> int;


private:
	int year;
	Month month;
	int day;
};

auto operator<<(std::ostream &out, Date const &d) -> std::ostream&;
auto operator>>(std::istream &in, Date &d) -> std::istream&;
auto operator<<(std::ostream &out, Date::DayOfWeek dayOfWeek) -> std::ostream&;

auto makeDate(std::istream &in) -> Date;


} // namespace calendar

#endif
