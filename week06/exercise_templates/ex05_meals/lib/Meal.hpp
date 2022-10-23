#ifndef SRC_MEAL_HPP_
#define SRC_MEAL_HPP_

#include <iosfwd>
#include <string>

enum class meal : int {
	breakfast, lunch, dinner
};

// Used for name <=> value conversion
struct {
	meal value;
	std::string name;
} const names[] = {
		{ meal::breakfast, "breakfast" },
		{ meal::lunch, "lunch"},
		{ meal::dinner, "dinner"}
};

std::istream& operator >>(std::istream& is, meal& m);

std::ostream& operator <<(std::ostream& os, meal const m);

// Type-safe operations
constexpr meal operator+(meal a, meal b) {
	return meal(static_cast<int>(a) + static_cast<int>(b));
}

constexpr meal operator+=(meal & a, meal b) {
	a = a + b;
	return a;
}

constexpr meal operator|(meal a, meal b) {
	return meal(static_cast<int>(a) | static_cast<int>(b));
}

constexpr meal operator&(meal a, meal b) {
	return meal(static_cast<int>(a) & static_cast<int>(b));
}

// Check distinctness
static_assert((meal::breakfast | meal::lunch | meal::dinner) == (meal::breakfast + meal::lunch + meal::dinner), "not distinct");

void count_meals(std::istream & input, std::ostream & output);

#endif /* SRC_MEAL_H_ */
