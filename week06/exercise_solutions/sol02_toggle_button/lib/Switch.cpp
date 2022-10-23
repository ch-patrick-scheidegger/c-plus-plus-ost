#include "Switch.hpp"

#include <array>
#include <string>

enum Switch::State : int {
	off, on, blinking
};

auto Switch::pressButton() -> void{
	state = static_cast<State>((state + 1) % 3);
}

auto operator <<(std::ostream &out, Switch const &s) -> std::ostream& {
	static std::array<std::string, 3> const stateNames { "off", "on", "blinking" };
	out << stateNames[s.state];
	return out;
}
