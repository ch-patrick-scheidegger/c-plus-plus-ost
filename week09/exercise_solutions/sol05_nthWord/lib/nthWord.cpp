#include "nthWord.hpp"
#include "Word.hpp"

#include <algorithm>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <tuple>
#include <utility>
#include <vector>

using word_input_iterator = std::istream_iterator<text::Word>;
using words_with_count = std::map<text::Word, unsigned>;
using count_word_pair = std::pair<unsigned, text::Word>;
using words = std::vector<count_word_pair>;

struct count_word_pair_comparator {
  auto operator()(count_word_pair const &lhs, count_word_pair const &rhs) const -> bool {
    return std::tie(rhs.first, lhs.second) < std::tie(lhs.first, rhs.second);
  }
};

auto count_words(std::istream &in) -> words_with_count {
  words_with_count word_occurrences{};
  std::for_each(word_input_iterator{in},
                word_input_iterator{},
                [&word_occurrences](text::Word const &word) {
                  word_occurrences[word]++;
                });
  return word_occurrences;
}

auto nth_word(words_with_count const &counts, unsigned n) -> text::Word {
  auto const n_index = n - 1;
  words all_words{};
  std::transform(
      std::begin(counts), std::end(counts),
      std::inserter(all_words, std::begin(all_words)),
      [](auto const &word_occurrence) {
        return std::make_pair(word_occurrence.second, word_occurrence.first);
      });
  std::nth_element(std::begin(all_words), std::begin(all_words) + n_index,
                   std::end(all_words), count_word_pair_comparator{});
  return all_words[n_index].second;
}

auto nth(std::istream &in, std::ostream &out, unsigned n) -> void {
  auto word_count = count_words(in);
  if (word_count.size() < n) {
    out << "Not enough words in input!\n";
    return;
  }
  out << nth_word(word_count, n) << '\n';
}
