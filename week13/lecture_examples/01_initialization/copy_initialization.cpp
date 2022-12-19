#include <string>

std::string string_factory() { return ""; }

void ci_function() {
	std::string in_place = string_factory();
	std::string copy = in_place;
	std::string c_string = "CPl";
}
