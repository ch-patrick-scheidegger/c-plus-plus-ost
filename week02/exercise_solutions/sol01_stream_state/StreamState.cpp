

#include <ios>
#include <iostream>

auto printIstreamState(std::ostream &out, std::istream &in) -> void {
  out << std::boolalpha;
  out << "Istream state:\n"
      << "\tgood: " << in.good() << '\n'
      << "\teof:  " << in.eof() << '\n'
      << "\tfail: " << in.fail() << '\n'
      << "\tbad:  " << in.bad() << '\n';
}

auto consumeIntAndPrintIstreamState(std::ostream &out, std::istream &in)
    -> void {
  int i;
  in >> i;
  printIstreamState(out, in);
}

auto main() -> int { consumeIntAndPrintIstreamState(std::cout, std::cin); }