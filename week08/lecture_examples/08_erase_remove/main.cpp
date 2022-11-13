#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

auto isPrime(unsigned u) -> bool {
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

auto erase_remove(std::ostream & out) -> void {
  auto values = std::vector{54u, 13u, 17u, 95u, 2u, 57u, 12u, 9u};
  auto is_prime = [](unsigned u) {
    return isPrime(u);
  };
  auto removed = std::remove_if(begin(values), end(values), is_prime);
  out << "begin to removed: ";
  std::copy(begin(values), removed, std::ostream_iterator<unsigned> { out, ", " });
  out << "\nremoved to old end: ";
  std::copy(removed, end(values), std::ostream_iterator<unsigned> { out, ", " });
}


auto main(int argc, char **argv) -> int {
  erase_remove(std::cout);
}