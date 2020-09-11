#ifndef DATE_H_
#define DATE_H_

#include <iosfwd>
#include <boost/operators.hpp>

namespace calendar {

class Date : boost::less_than_comparable<Date>, boost::equality_comparable<Date> {
	int year, month, day;

public:
	Date();
	explicit Date(std::istream &in);
	Date(int year, int month, int day);

	Date nextDay() const;

	bool operator <(Date const &rhs) const;
	bool operator==(Date const &rhs) const;

	static bool isValidYear(int year);
	static bool isLeapYear(int year);
	static bool isValidDate(int year, int month, int day);
	static bool isValidSeparator(char ch);
	static int endOfMonth(int year, int month);

	friend std::ostream& operator<<(std::ostream &out, Date const &d);
	friend std::istream& operator>>(std::istream &in, Date &d);
};

Date makeDate(std::istream &in);

}// namespace calendar

#endif /* DATE_H_ */
