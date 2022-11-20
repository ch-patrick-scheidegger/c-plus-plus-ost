#ifndef ROTATE3ARGUMENTS_HPP_
#define ROTATE3ARGUMENTS_HPP_

#include <utility>

template <typename T>
auto rotate3arguments(T &a, T &b, T &c) -> void {
  std::swap(a, b); // using swap avoids unnecessary copying and temporaries
  std::swap(b, c);
}

#endif
