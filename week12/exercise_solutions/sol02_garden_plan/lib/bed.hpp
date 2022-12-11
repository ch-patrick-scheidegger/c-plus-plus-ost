#ifndef BED_HPP
#define BED_HPP

#include <iosfwd>
#include <string>

struct Bed
{
    virtual ~Bed() = default;

    auto print(std::ostream & output) const -> void;

    auto virtual pegs() const -> unsigned = 0;
    auto virtual ropes() const -> double = 0;
    auto virtual seeds() const -> double = 0;

protected:
    auto virtual name() const -> std::string = 0;
};

#endif