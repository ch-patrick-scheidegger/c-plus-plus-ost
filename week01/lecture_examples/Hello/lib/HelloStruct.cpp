#include "HelloStruct.hpp"

#include <ostream>

auto Hello::sayHello(std::ostream& out) const -> void {
	out << "Hello, world!\n";
}
