#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

bool isPrime(int value) {
	return true;
}

auto primes(std::vector<unsigned> const & values) {
	std::vector<unsigned> primeValues{};
	copy_if(begin(values), end(values), std::back_inserter(primeValues), isPrime);
	return primeValues;
}

int main() {
	std::istream_iterator<unsigned> inIter{std::cin};
	std::istream_iterator<unsigned> eof{};
	std::vector<unsigned> const values{inIter, eof};
	std::ostream_iterator<unsigned> out{std::cout};
	copy(begin(primes(values)), end(primes(values)), out);
}
