#include "Switch.hpp"

#include <array>
#include <string>

enum Switch::State : int {
	off, on, blinking
};

auto Switch::pressButton() -> void{
	state = static_cast<State>((state + 1) % 3);
}

auto Switch::print(std::ostream& out) const  -> void {
	static std::array<std::string, 3> const stateNames { "off", "on", "blinking" };
	out << stateNames[state];
}

auto operator <<(std::ostream &out, Switch const &s) -> std::ostream& {
	s.print(out);
	return out;
}
