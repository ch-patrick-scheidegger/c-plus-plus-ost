#include "Statistics.hpp"
#include "Word.hpp"

#include <algorithm>
#include <cstddef>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <ranges>
#include <set>
#include <stdexcept>

namespace statistics {

// auto printOccurrences(std::istream& in, std::ostream& out, int n) -> void {
//   auto const occurrences = histogram(in);
//   auto const topOccurrences = top(occurrences, n);
//   std::ranges::copy(topOccurrences,
//                     std::ostream_iterator<HistogramEntry>{out, "\n"});
// }

// auto histogram(std::istream& in) -> std::map<text::Word, int> {
//   std::map<text::Word, int> result{};
//   std::ranges::for_each(std::ranges::istream_view<text::Word>{in},
//                         [&result](auto const& word) { result[word]++; });
//   return result;
// }

 auto top(std::map<text::Word, int> const& occurrences, int n)
     -> std::set<statistics::HistogramEntry> {
   if (n < 0) {
     throw std::invalid_argument{"n must not be negative"};
   }
   std::set<statistics::HistogramEntry> result{};
   std::ranges::transform(occurrences,
                  std::inserter(result, std::begin(result)),
                  [](auto const& entry) {
                    return HistogramEntry{entry.first, entry.second};
                  });
   auto elementsInResult =
       std::min(static_cast<std::size_t>(n), result.size());
   auto start = std::next(std::begin(result), elementsInResult);
   result.erase(start, std::end(result));
   return result;
 }

// auto operator<<(std::ostream& out, HistogramEntry const& entry) -> std::ostream& {
//   return out << entry.word << ": " << entry.occurrences;
// }

}  // namespace statistics
