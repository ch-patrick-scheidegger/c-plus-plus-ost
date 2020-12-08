#include <string>
#include <vector>

void li_function() {
	std::string direct { "CPl" };
	std::string copy = { "CPlA" };
}

// vector(size_type count,
//        const T& value,
//        const Allocator& alloc = Allocator());

int ouch() {
	std::vector data{10, 42};
	return data[5];
}
