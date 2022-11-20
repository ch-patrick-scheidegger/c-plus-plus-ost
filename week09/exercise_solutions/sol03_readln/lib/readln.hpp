#ifndef READLN_HPP_
#define READLN_HPP_

#include <istream>
#include <sstream>
#include <string>

namespace readln_impl {

template <typename... I>
auto doread(std::istream &in, I &...vars) -> void;

auto doread(std::istream &in, std::string &rest) -> void {
  getline(in, rest); // consume the rest of the line into rest
}

template <typename FIRST, typename... I>
auto doread(std::istream &in, FIRST &var, I &...vars) -> void {
  in >> var;
  if (sizeof...(I))
    doread(in, vars...);
}

} // namespace readln_impl

template <typename... I>
auto readln(std::istream &in, I &...vars) -> void {
  using namespace readln_impl;
  std::string line{};
  getline(in, line);
  std::istringstream input{line};
  doread(input, vars...);
  if (input.fail()) {
    in.setstate(std::ios::failbit);
  }
}

#endif
