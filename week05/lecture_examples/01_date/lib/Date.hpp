#ifndef DATE_HPP_
#define DATE_HPP_

#include <compare>
#include <iosfwd>

class Date {
  int year{1980};
  int month{1};
  int day{1};
public:
  Date(int year, int month, int day);
  Date() = default;

  static auto isLeapYear(int year) -> bool;
  static auto lastDayOfMonth(int year, int month) -> int;
  auto tomorrow() const -> Date;
  auto print(std::ostream& output) const -> void;

  auto operator<=>(Date const& right) const -> std::strong_ordering {
    if (year != right.year) {
        return year <=> right.year;
    }
    if (month != right.month) {
        return month <=> right.month;
    }
    return day <=> right.day;
  }
  auto operator==(Date const& right) const -> bool {
    return (*this <=> right) == std::strong_ordering::equal;
  }
  // auto operator<=>(Date const& right) const = default;

private:
  auto isValidDate() const -> bool;
};

auto operator>>(std::istream& input, Date& date) -> std::istream&;
auto operator<<(std::ostream& output, Date const& date) -> std::ostream&;


#endif