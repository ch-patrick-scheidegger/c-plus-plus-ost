#ifndef PRIMES_HPP_
#define PRIMES_HPP_

#include <iosfwd>

auto is_prime(unsigned long long n) -> bool;

auto primes(std::ostream & out, unsigned long long limit) -> void;

#endif
