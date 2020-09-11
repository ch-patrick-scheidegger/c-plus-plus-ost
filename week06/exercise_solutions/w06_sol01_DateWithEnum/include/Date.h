#ifndef DATE_H_
#define DATE_H_

#include <iosfwd>
#include <boost/operators.hpp>

namespace calendar {

struct Date : boost::less_than_comparable<Date>, boost::equality_comparable<Date> {
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

	Date nextDay() const;
	DayOfWeek dayOfWeek() const;

	bool operator <(Date const &rhs) const;
	bool operator==(Date const &rhs) const;

	static bool isValidYear(int year);
	static bool isLeapYear(int year);
	static bool isValidDate(int year, Month month, int day);
	static bool isValidSeparator(char ch);
	static int endOfMonth(int year, Month month);

	friend std::ostream& operator<<(std::ostream &out, Date const &d);
	friend std::istream& operator>>(std::istream &in, Date &d);

private:
	int year;
	Month month;
	int day;
};

Date makeDate(std::istream &in);

std::ostream& operator <<(std::ostream &out, Date::DayOfWeek dayOfWeek);

}// namespace calendar

#endif /* DATE_H_ */
