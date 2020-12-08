#include <string>
#include <iostream>

int global_variable; // implicitly static

std::string global_text;

void di_function() {
	static long local_static;

	long local_variable;
	std::string local_text;
}

struct di_class {

	di_class() = default;

	char member_variable; // not in ctor init list

};

struct blob {
	blob(int);
};

//blob static_instance;

void print_uninitialized() {
	int my_number;
	std::cout << my_number << '\n';
}
