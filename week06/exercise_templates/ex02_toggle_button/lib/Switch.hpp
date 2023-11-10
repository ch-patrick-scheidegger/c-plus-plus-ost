#ifndef SWITCH_HPP_
#define SWITCH_HPP_

#include <iosfwd>

class Switch {
public:
    auto pressButton() -> void;

private:
    enum SwitchState {
        off, on, blinking
    };
    SwitchState state = off;
};

auto operator<<(std::ostream &out, Switch const &d) -> std::ostream&;

#endif
