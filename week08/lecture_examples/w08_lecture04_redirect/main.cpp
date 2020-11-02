#include <iostream>
#include <iterator>
#include <algorithm>

void redirect(std::istream & in, std::ostream & out) {
  using in_iter = std::istream_iterator<char>;
  using out_iter = std::ostream_iterator<char>;
  std::copy(in_iter{in}, in_iter{}, out_iter{out});
}
int main(int argc, char **argv) {
	redirect(std::cin, std::cout);
}
