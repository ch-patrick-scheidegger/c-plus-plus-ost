#ifndef DATE_H_
#define DATE_H_
#include <iosfwd>
#include <boost/operators.hpp>
#include <optional>

namespace date {

struct Date
/*
 : private boost::less_than_comparable<Date> {
 //...
 */
: private boost::less_than_comparable<Date>, boost::equality_comparable<Date> {

	Date() = default;
	explicit Date(std::istream& in);
	void print(std::ostream& out) const;
	static bool isValidYear(int year);
	static bool isLeapYear(int year);
	static bool isValidDate(int year, int month, int day);
	Date(int year, int month, int day);
	static int endOfMonth(int year, int month);
	void nextDay();
	bool operator <(Date const& rhs) const;
	void read(std::istream& in);
	static bool isValidSep(char ch);
	bool operator==(Date const& rhs) const {
		return year == rhs.year && month == rhs.month && day == rhs.day;
	}
	// "hidden friends" speed up compilation
	friend inline std::ostream&
	operator<<(std::ostream& out, Date const& d) {
		d.print(out); // delegate to reduce header dependencies
		return out;
	}

	friend inline std::istream&
	operator>>(std::istream& in, Date& d) {
		d.read(in); // delegate to reduce header dependencies
		return in;
	}

	//...
private:
	int year { 9999 };
	int month { 12 };
	int day { 31 };
//public: bool operator!=(Date const&)const;

//...
};

std::optional<Date> make_date(std::istream& in);
//...
}// namespace date
#endif /* DATE_H_ */
