#include <iostream>
#include <iterator>
#include <algorithm>

auto redirect(std::istream & in, std::ostream & out) -> void {
  using in_iter = std::istream_iterator<char>;
  using out_iter = std::ostream_iterator<char>;
  std::copy(in_iter{in}, in_iter{}, out_iter{out});
}

auto main(int argc, char **argv) -> int {
  redirect(std::cin, std::cout);
}
