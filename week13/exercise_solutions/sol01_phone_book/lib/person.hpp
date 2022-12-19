#ifndef PERSON_HPP
#define PERSON_HPP

#include <compare>
#include <ostream>
#include <string>

struct Person {
    std::string firstName;
    std::string lastName;

    auto operator<=>(Person const &) const -> std::strong_ordering = default;
};

auto operator<<(std::ostream & out, Person const & obj) -> std::ostream & {
    return out << obj.lastName << ", " << obj.firstName;
}

#endif