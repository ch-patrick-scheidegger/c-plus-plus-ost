#ifndef DATE_HPP_
#define DATE_HPP_

#include <compare>
#include <iosfwd>


namespace calendar {

class Date {
	int year, month, day;

public:
	Date();
	explicit Date(std::istream &in);
	Date(int year, int month, int day);

	auto nextDay() const -> Date;
	auto print(std::ostream& out) const -> void;

	auto operator <=>(Date const &rhs) const = default;

	static auto isValidYear(int year) -> bool;
	static auto isLeapYear(int year) -> bool;
	static auto isValidDate(int year, int month, int day) -> bool;
	static auto isValidSeparator(char ch) -> bool;
	static auto endOfMonth(int year, int month) -> int;

};

auto operator<<(std::ostream &out, Date const &d) -> std::ostream&;
auto operator>>(std::istream &in, Date &d) -> std::istream&;

auto makeDate(std::istream &in) -> Date;

} // namespace calendar

#endif
