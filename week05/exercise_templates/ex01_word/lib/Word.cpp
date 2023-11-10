
#include "Word.hpp"
#include <algorithm>
#include <istream>
#include <stdexcept>

namespace text {
    auto Word::print(std::ostream & os) const -> std::ostream& {
        return os << word;
    }

    Word::Word() : Word("Word") {}

    Word::Word(std::string str) : word{str}{
        if(word.empty()) {
            throw std::invalid_argument{"Word must not be empty"};
        }
        bool containsNonAlphanumeric = std::ranges::any_of(word, [](char c) { return std::isalpha(c) == 0;});
        if(containsNonAlphanumeric) {
            throw std::invalid_argument{"Word must only contain alphanumeric characters"};
        }
    }

    auto Word::readFrom(std::istream &is) -> std::istream& {
        bool wordStarted = false;
        while (is.good()) {
            char character = is.peek();

            if (isalpha(character)) {
                is.ignore();

                if (wordStarted) {
                    word += character;
                } else {
                    word = character;
                    wordStarted = true;
                }
            } else {
                if (!wordStarted) {
                    is.ignore();
                } else {
                    break;
                }
            }
        }
        if (!wordStarted) {
            is.setstate(std::ios_base::failbit);
        }

        return is;
    }

    auto areEqualIgnoringCase(unsigned char a, unsigned char b)-> bool {
        return std::tolower(a) == std::tolower(b);
    }

    auto Word::operator==(const Word &right) const -> bool {
        return (*this <=> right) == std::strong_ordering::equal;
    }

    auto Word::operator<=>(const Word &right) const -> std::weak_ordering {
        auto mismatchResult = std::mismatch(word.begin(), word.end(),
                                            right.word.begin(), right.word.end(), areEqualIgnoringCase);
        if (mismatchResult.first == word.end() && mismatchResult.second == right.word.end()) {
            return std::weak_ordering::equivalent;
        }
        return tolower(*mismatchResult.first) <=> tolower(*mismatchResult.second);
    }
}

