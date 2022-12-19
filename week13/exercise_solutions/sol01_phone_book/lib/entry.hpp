#ifndef ENTRY_HPP
#define ENTRY_HPP

#include "address.hpp"
#include "person.hpp"
#include <ostream>
#include <string>

struct Entry {
    Person person;
    std::string phoneNumber;
    Address address;

    auto operator<=>(Entry const &) const -> std::strong_ordering = default;
};

auto operator<<(std::ostream & out, Entry const & obj) -> std::ostream & {
    return out << obj.person << '\n' << obj.phoneNumber << '\n' << obj.address;
}

#endif