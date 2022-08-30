#ifndef HELLOSTRUCT_HPP_
#define HELLOSTRUCT_HPP_

#include <iosfwd>

struct Hello {
	auto sayHello(std::ostream& out) const -> void;
};

#endif