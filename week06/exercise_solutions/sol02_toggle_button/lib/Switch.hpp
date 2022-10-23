#ifndef SWITCH_HPP_
#define SWITCH_HPP_

#include <iosfwd>

struct Switch {
	enum State : int;
	auto pressButton() -> void;
	friend auto operator <<(std::ostream &out, Switch const &s) -> std::ostream&;
private:
	State state;
};

#endif
