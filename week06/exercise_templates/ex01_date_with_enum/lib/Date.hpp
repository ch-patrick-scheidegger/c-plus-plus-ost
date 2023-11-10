#ifndef DATE_HPP_
#define DATE_HPP_

#include <compare>
#include <iosfwd>


namespace calendar {

enum class Month {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

class Date {
	int year;
    Month month;
    int day;

public:
	Date();
	explicit Date(std::istream &in);
	Date(int year, int month, int day);
    explicit Date(int year, Month month, int day);

	auto nextDay() const -> Date;
	auto print(std::ostream& out) const -> void;

	auto operator <=>(Date const &rhs) const = default;

	static auto isValidYear(int year) -> bool;
	static auto isLeapYear(int year) -> bool;
	static auto isValidDate(int year, Month month, int day) -> bool;
	static auto isValidSeparator(char ch) -> bool;
	static auto endOfMonth(int year, Month month) -> int;

};

auto operator<<(std::ostream &out, Date const &d) -> std::ostream&;
auto operator>>(std::istream &in, Date &d) -> std::istream&;

auto makeDate(std::istream &in) -> Date;

} // namespace calendar

#endif
