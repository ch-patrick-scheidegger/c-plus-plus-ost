#include "meal.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <istream>
#include <exception>

struct attendee {
	std::string const name;
	meal const meals; //set of meals
};

using attendees = std::vector<attendee>;

attendees get_attendees(std::istream & is) {
	attendees result;
	std::string line;
	while (std::getline(is, line)) {
		std::istringstream iss{line};
		std::string name;
		iss >> name;
		meal meal, meals{};
		while (iss >> meal) {
			meals += meal; // add in each meal
		}
		if (is.fail()) {
			throw std::runtime_error{"Input error"};
		}
		result.push_back({name, meals});
	}
	return result;
}

size_t count(attendees a, meal m) {
	size_t result{};
	for (auto & item : a) {
		if ((item.meals & m) == m) {
			++result;
		}
	}
	return result;
}

void count_meals(std::istream & input, std::ostream & output) try {
	auto attendees = get_attendees(input);
	output << "Total: " << attendees.size();
	for (auto m : {meal::breakfast, meal::lunch, meal::dinner}) {
		output << ' ' << m << ": " << count(attendees, m);
	}
	output << '\n';
} catch (std::exception const & ex) {
	output << ex.what() << '\n';
}

std::istream& operator >>(std::istream& is, meal& m) {
	std::string name;
	if (is >> name) {
		for (auto p : names) {
			if (p.name == name) {
				m = p.value;
			}
		}
	}
	return is;
}

std::ostream & operator <<(std::ostream& os, meal const m) {
	for (auto p : names) {
		if (p.value == m) {
			os << p.name;
		}
	}
	return os;
}
