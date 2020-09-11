#include "Switch.h"

#include <array>
#include <string>

enum Switch::State : int {
	off, on, blinking
};

void Switch::pressButton() {
	state = static_cast<State>((state + 1) % 3);
}

std::ostream& operator <<(std::ostream &out, Switch const &s) {
	static std::array<std::string, 3> const stateNames { "off", "on", "blinking" };
	out << stateNames[s.state];
	return out;
}
