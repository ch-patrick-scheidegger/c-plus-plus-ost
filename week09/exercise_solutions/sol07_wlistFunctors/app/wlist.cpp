#include "Word.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>

struct WordLengthComparator {
  auto operator()(text::Word const &lhs, text::Word const &rhs) const -> bool {
    auto lhsContent = wordToString(lhs);
    auto rhsContent = wordToString(rhs);
    return lhsContent.length() < rhsContent.length() ||
           (lhsContent.length() == rhsContent.length() && lhs < rhs);
  }

private:
  static auto wordToString(text::Word const &word) -> std::string {
    std::ostringstream wordContent{};
    wordContent << word;
    return wordContent.str();
  }
};

auto wlist(std::istream &in, std::ostream &out) -> void {
  using inIter = std::istream_iterator<text::Word>;

  // Descending: std::set<text::Word, std::greater<>> words{intIter{in}, inIter{}};
  std::set<text::Word, WordLengthComparator> words{inIter{in}, inIter{}};
  copy(begin(words), end(words), std::ostream_iterator<text::Word>{out, "\n"});
}

auto main() -> int {
  wlist(std::cin, std::cout);
}
