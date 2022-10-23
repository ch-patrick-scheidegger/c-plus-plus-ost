#include "Field5.hpp"

#include <ostream>

auto operator <<(std::ostream& out, const Field5& r) -> std::ostream& {
	out << "Field5{" << r.value() << '}';
	return out;
}
