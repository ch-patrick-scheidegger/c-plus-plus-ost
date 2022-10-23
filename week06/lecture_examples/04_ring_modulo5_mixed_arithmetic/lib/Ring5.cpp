#include "Ring5.hpp"

#include <ostream>

auto operator <<(std::ostream& out, const Ring5& r) -> std::ostream& {
	out << "Ring5{" << r.value() << '}';
	return out;
}
Ring5::Ring5(unsigned x) : val{x % 5} {}
