#include "Statistics.hpp"

#include <istream>
#include <algorithm>
#include <iostream>

namespace statistics {

    auto histogram(std::istream& in) -> std::map<text::Word, int> {
        std::map<text::Word, int> wordMap {};
        text::Word word{};
        while(in.good()){
            in >> word;
            wordMap[word]++;
        }
        return wordMap;
    }

    HistogramEntry::HistogramEntry(text::Word word, int count) : word{word}, count{count} {}

    auto HistogramEntry::print(std::ostream &os) const -> std::ostream & {
        return os << word << ": " << count;
    }

    auto HistogramEntry::operator<=>(const HistogramEntry &right) const -> std::weak_ordering {
        if(count > right.count) {
            return std::weak_ordering::less;
        }
        if(count < right.count) {
            return std::weak_ordering::greater;
        }
        return word <=> right.word;
    }

    auto top(const std::map<text::Word, int> &occurrences, int n) -> std::set<HistogramEntry> {
        std::set<HistogramEntry> mostOccurrences{};
        if(n == 0) {
            return mostOccurrences;
        }
        int amount = 0;
        for(auto i = occurrences.crbegin(); i != occurrences.crend(); i++, amount++) {
            if(amount == n){
                return mostOccurrences;
            }
            auto pair = *i;
            mostOccurrences.insert(HistogramEntry(pair.first, pair.second));
        }
        return mostOccurrences;
    }

}
