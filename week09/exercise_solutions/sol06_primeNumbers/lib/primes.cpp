#include "primes.hpp"

#include <boost/iterator/counting_iterator.hpp>

#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <numeric>
#include <ostream>
#include <vector>

auto is_prime(unsigned long long n) -> bool {
  if (n == 2) {
    return true;
  }
  if (n == 0 || n == 1 || n % 2 == 0) {
    return false;
  }
  for (auto divisor = 3ull; divisor * divisor <= n; divisor += 2) {
    if (n % divisor == 0) {
      return false;
    }
  }
  return true;
}

auto is_prime_loopless(unsigned long long n) -> bool {
  if (n < 2) {
    return false;
  }
  std::vector<unsigned long long> divisors(n - 2);
  std::iota(std::begin(divisors), std::end(divisors), 2);
  return std::none_of(std::begin(divisors), std::end(divisors),
                      [n](auto div) { return n % div == 0; });
}

auto is_prime_boost(unsigned long long n) -> bool {
  using std::placeholders::_1;
  if (n == 2) {
    return true;
  }
  if (n == 0 || n == 1 || n % 2 == 0) {
    return false;
  }
  unsigned long long rootOfN = std::sqrt(n) + 1;
  return std::all_of(boost::counting_iterator<unsigned long long>{3},
                     boost::counting_iterator<unsigned long long>{rootOfN},
                     std::bind(std::modulus<>{}, n, _1));
}

auto primes(std::ostream &out, unsigned long long limit) -> void {
  std::vector<unsigned long long> primes(limit);
  std::iota(std::begin(primes), std::end(primes), 1);
  std::copy_if(std::begin(primes), std::end(primes),
               std::ostream_iterator<unsigned long long>{out, "\n"},
               is_prime_boost);
}