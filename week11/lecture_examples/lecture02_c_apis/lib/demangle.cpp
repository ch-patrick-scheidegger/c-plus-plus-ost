#include "demangle.hpp"

#include <cstdlib>
#include <cxxabi.h>
#include <memory>

auto demangle(std::string const & name) -> std::string {
  auto cleanup = [] (char * ptr){
    free(ptr);
  };

  std::unique_ptr<char, decltype(cleanup)> toBeFreed {
    __cxxabiv1::__cxa_demangle(name.c_str(), 0, 0, 0),
    cleanup
  };

  std::string result(toBeFreed.get());
  return result;
}
