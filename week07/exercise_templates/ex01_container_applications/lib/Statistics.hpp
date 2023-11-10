#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include "Word.hpp"

#include <iosfwd>
#include <map>
#include <set>

namespace statistics {

    class HistogramEntry {
    public:
        HistogramEntry(text::Word word, int count);
        auto print(std::ostream& os) const -> std::ostream&;
        auto operator<=>(HistogramEntry const& right) const -> std::weak_ordering;
        auto operator==(HistogramEntry const& right) const -> bool = default;

    private:
        int count;
        text::Word word;
    };

    inline auto operator<<(std::ostream& os, HistogramEntry const& right) -> std::ostream& {
        return right.print(os);
    }

    auto histogram(std::istream&) -> std::map<text::Word, int>;
    auto top(std::map<text::Word, int> const& occurrences, int n) -> std::set<HistogramEntry>;

} // namespace statistics

#endif