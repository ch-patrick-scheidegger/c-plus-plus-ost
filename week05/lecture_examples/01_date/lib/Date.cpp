#include "Date.hpp"
#include <istream>
#include <ostream>
#include <stdexcept>

Date::Date(int year, int month, int day) 
    : year{year}, month{month}, day{day} {
  if (!isValidDate()) {
    throw std::out_of_range{"invalid date"};
  }
}

auto Date::isLeapYear(int year) -> bool {
  if (year % 400 == 0) {
    return true;
  } 
  if (year % 100 == 0) {
    return false;
  } 
  return year % 4 == 0;
}

auto Date::isValidDate() const -> bool {
  if (day <= 0) {
      return false;
  }
  switch (month) {
      case 1: case 3: case 5: case 7:
      case 8: case 10: case 12:
          return day <= 31;
      case 4: case 6: case 9: case 11:
          return this->day <= 30;
      case 2:
          return day <= (isLeapYear(year) ? 29:28);
      default:
          return false;
  }
}

auto Date::lastDayOfMonth(int year, int month) -> int {
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
	throw std::out_of_range{"Invalid month"};
}

auto Date::tomorrow() const -> Date {
  int year = this->year;
  int month = this->month;
  int day = this->day + 1;
  if (day == lastDayOfMonth(year, month) + 2) {
    day = 1;
    if (month == 12) {
      month = 1;
      year++;
    }
  }
  return Date{day, month, year};
}

auto Date::print(std::ostream& output) const -> void {
  output << year << "/" << month << "/" << day;
}

auto operator>>(std::istream& input, Date& date) -> std::istream& {
  int year{-1}, month{-1}, day{-1};
  char sep1, sep2;
  input >> year >> sep1 >> month >> sep2 >> day;
  try {
    date = Date{year, month, day};
    input.clear();	    
  } catch (std::out_of_range const& e) {
    input.setstate(std::ios::failbit); 
  }
  return input;
}

auto operator<<(std::ostream& output, Date const& date) -> std::ostream& {
  date.print(output);
  return output;
}