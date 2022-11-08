#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include "Word.hpp"

#include <compare>
#include <map>
#include <set>
#include <tuple>

namespace statistics {

struct HistogramEntry {
//   text::Word word;
//   int occurrences;

//   auto operator<=>(HistogramEntry const& other) const -> std::weak_ordering {
//     if (auto cmpResult = occurrences <=> other.occurrences;
//         cmpResult != std::strong_ordering::equal) {
//       return cmpResult == std::strong_ordering::less ? std::strong_ordering::greater : std::strong_ordering::less;
//     }
//     return word <=> other.word;
//   }

//   auto operator==(HistogramEntry const& other) const -> bool {
// 	return (*this <=> other) == std::weak_ordering::equivalent;
//   }
};

// auto operator<<(std::ostream& out, HistogramEntry const& entry)
//     -> std::ostream&;

// auto top(std::map<text::Word, int> const& occurrences, int n)
//     -> std::set<statistics::HistogramEntry>;

// auto histogram(std::istream& in) -> std::map<text::Word, int>;

// auto printOccurrences(std::istream& in, std::ostream& out, int n) -> void;

}  // namespace statistics

#endif
