#ifndef MEDIAN_HPP_
#define MEDIAN_HPP_

#include <algorithm>
#include <string>

template <typename T>
auto median(T const &a, T const &b, T const &c) -> T const & {
  return std::max(std::min(a, b), std::min(std::max(a, b), c));
}

// overload for pointers, don't allow pointers
template <typename T> auto median(T *a, T *b, T *c) -> T * = delete;

// overload for string literals
auto median(char const *ap, char const *bp, char const *cp) -> std::string {
  std::string a{ap};
  std::string b{bp};
  std::string c{cp};
  return median(a, b, c);
}

#endif
