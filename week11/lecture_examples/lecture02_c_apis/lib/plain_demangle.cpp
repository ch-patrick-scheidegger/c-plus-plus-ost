#include "plain_demangle.hpp"

#include <cstdlib>
#include <cxxabi.h>
#include <memory>

struct free_deleter {
  template<typename T>
  auto operator()(T * p) const -> void {
    free(const_cast<std::remove_const_t<T> *>(p));
  }
};

template<typename T>
using unique_C_ptr = std::unique_ptr<T, free_deleter>;

auto plain_demangle(char const * name) -> std::string {
  unique_C_ptr<char> toBeFreed{__cxxabiv1::__cxa_demangle(name, nullptr, nullptr, nullptr)};
  std::string result(toBeFreed.get());
  return result;
}
