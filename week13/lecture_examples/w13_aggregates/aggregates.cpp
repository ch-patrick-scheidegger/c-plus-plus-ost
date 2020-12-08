#include <string>
#include <ostream>
#include <iostream>

struct person {
	std::string name;
	int age{42};

	bool operator<(person const & other) const {
		return age < other.age;
	}

	void write(std::ostream & out) const {
		out << name << ": " << age << '\n';
	}
};


int main()
{
	person rudolf{"Rudolf", 32};
	rudolf.write(std::cout);
}
