#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

bool isPrime(unsigned u) {
	if (u == 0 || u == 1) {
		return false;
	}
	for (unsigned div = 2; div < u; div++) {
		if (u % div == 0) {
			return false;
		}
	}
	return true;
}

void erase_remove(std::ostream & out) {
	std::vector<unsigned> values { 54, 13, 17, 95, 2, 57, 12, 9 };
	auto is_prime = [](unsigned u) {
		return isPrime(u);
	};
	auto removed = std::remove_if(begin(values), end(values), is_prime);
	out << "begin to removed: ";
	std::copy(begin(values), removed, std::ostream_iterator<unsigned> { out, ", " });
	out << "\nremoved to old end: ";
	std::copy(removed, end(values), std::ostream_iterator<unsigned> { out, ", " });
}


int main(int argc, char **argv) {
	erase_remove(std::cout);

}