#ifndef SWITCH_HPP_
#define SWITCH_HPP_

#include <iosfwd>

struct Switch {
	enum State : int;
	auto pressButton() -> void;
	auto print(std::ostream& out) const -> void;
private:
	State state;
};
auto operator <<(std::ostream &out, Switch const &s) -> std::ostream&;

#endif
