#include "wcount.hpp"
#include "Word.hpp"

#include <istream>
#include <iterator>

auto wcount(std::istream& in) -> unsigned {
  using word_iterator = std::istream_iterator<text::Word>;
  return std::distance(word_iterator{in}, word_iterator{});
}
