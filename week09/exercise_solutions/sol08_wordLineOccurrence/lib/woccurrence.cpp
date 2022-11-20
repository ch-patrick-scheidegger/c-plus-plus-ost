#include "woccurrence.hpp"
#include "Word.hpp"

#include <algorithm>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using word_line = std::vector<text::Word>;

namespace text {

using word_iterator = std::istream_iterator<Word>;

auto operator>>(std::istream &in, word_line &line) -> std::istream & {
  std::string input_line{};
  if (std::getline(in, input_line)) {
    line.clear();
    std::istringstream line_stream{input_line};
    std::copy(word_iterator{line_stream}, word_iterator{},
              std::back_inserter(line));
  }
  return in;
}

} // namespace text

struct word_line_collector {
  void operator()(word_line const &line) {
    line_number++;
    std::for_each(
        std::begin(line), std::end(line),
        [this](text::Word const &w) { word_lines[w].insert(line_number); });
  }

  auto print(std::ostream &out) const -> void {
    std::for_each(std::begin(word_lines), std::end(word_lines),
                  [&](auto const &word_line) {
                    out << word_line.first << " ";
                    std::copy(std::begin(word_line.second),
                              std::end(word_line.second),
                              std::ostream_iterator<unsigned>{out, " "});
                    out << '\n';
                  });
  }

private:
  unsigned line_number{};
  std::map<text::Word, std::set<unsigned>> word_lines{};
};

auto operator<<(std::ostream &out, word_line_collector const &collector) -> std::ostream & {
  collector.print(out);
  return out;
}

auto woccurrence(std::istream &in, std::ostream &out) -> void {
  std::istream_iterator<word_line> line_iterator{in}, eof{};
  out << std::for_each(line_iterator, eof, word_line_collector{});
}
