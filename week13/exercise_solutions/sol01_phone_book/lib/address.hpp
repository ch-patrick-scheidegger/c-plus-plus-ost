#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <cstdint>
#include <ostream>
#include <string>

struct Address {
    std::string street;
    std::uint32_t streetNumber;
    std::uint32_t zipCode;
    std::string city;

    auto operator<=>(Address const &) const -> std::strong_ordering = default;
};

auto operator<<(std::ostream & out, Address const & obj) -> std::ostream & {
    return out << obj.street << ' '  << obj.streetNumber << '\n' << obj.zipCode << ' ' << obj.city;
}

#endif