#include "Date.hpp"

#include <algorithm>
#include <array>
#include <iomanip>
#include <istream>
#include <iterator>
#include <ostream>
#include <stdexcept>


namespace calendar {

Date::Date(int year, Month month, int day) : year{year}, month{month}, day{day} {
    if (!isValidDate(year, month, day)) {
        throw std::out_of_range{"invalid date"};
    }
}

auto Date::print(std::ostream& out) const -> void {
  auto const previousFillChar = out.fill('0');
  out << std::setw(2) << day << '.';
  out << std::setw(2) << static_cast<int>(month) << '.';
  out << std::setw(4) << year;
  out.fill(previousFillChar);
}

auto operator<<(std::ostream& out, Date const& date) -> std::ostream& {
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
  return isValidYear(year) && static_cast<int>(month) > 0 && static_cast<int>(month) < 13 && day > 0 &&
         day <= endOfMonth(year, month);
}

Date::Date(int year, int month, int day) : Date(year, static_cast<Month>(month), day) {}

Date::Date() : year{9999}, month{Month::December}, day{31} {}

auto Date::endOfMonth(int year, Month month) -> int {
  switch (month) {
    case Month::January:
    case Month::March:
    case Month::May:
    case Month::July:
    case Month::August:
    case Month::October:
    case Month::December:
      return 31;
    case Month::April:
    case Month::June:
    case Month::September:
    case Month::November:
      return 30;
    case Month::February:
      return (isLeapYear(year) ? 29 : 28);
  }
  throw std::invalid_argument{"invalid month"};
}

auto Date::nextDay() const -> Date {
  auto tomorrowDay = (day == endOfMonth(year, month)) ? 1 : day + 1;
  auto tomorrowMonth = month;
  auto tomorrowYear = year;
  if (tomorrowDay == 1) {
    tomorrowMonth = (month == Month::December) ? Month::January : static_cast<Month>(static_cast<int>(month) + 1);
    if (tomorrowMonth == Month::January) {
      tomorrowYear++;
    }
  }
  return {tomorrowYear, tomorrowMonth, tomorrowDay};
}

std::array<char, 3> const validSeparators{'.', '/', '-'};

auto Date::isValidSeparator(char separator) -> bool {
  return std::find(cbegin(validSeparators), cend(validSeparators), separator) !=
         cend(validSeparators);
}

auto operator>>(std::istream& in, Date& date) -> std::istream& {
  int inDay{}, inMonth{}, inYear{};
  char sep1{}, sep2{};
  in >> inDay >> sep1 >> inMonth >> sep2 >> inYear;
  if (Date::isValidYear(inDay)) {
    std::swap(inDay, inYear);
  }
  if (inYear >= 0 && inYear < 100) {
    inYear += 2000;
  }
  if (!in.fail() && Date::isValidSeparator(sep1) && sep1 == sep2 &&
      Date::isValidDate(inYear, static_cast<Month>(inMonth), inDay)) {
    date = Date{inYear, inMonth, inDay};
  } else {
    in.setstate(std::ios::failbit);
  }
  return in;
}

Date::Date(std::istream& in) : year{}, month{}, day{} {
  in >> *this;
  if (in.fail()) {
    throw std::out_of_range{"invalid date"};
  }
}



auto makeDate(std::istream& in) -> Date try {
  return Date{in};
} catch (std::out_of_range const&) {
  return Date{};  // default value
}

}  // namespace calendar
