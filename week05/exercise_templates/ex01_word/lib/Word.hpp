#ifndef WORD_HPP_
#define WORD_HPP_

#include <iosfwd>
#include <string>

namespace text {
    class Word {
    public:
        Word();
        explicit Word(std::string str);
        auto print(std::ostream& os) const -> std::ostream&;
        auto readFrom(std::istream& is) -> std::istream&;
        auto operator==(Word const& right) const -> bool;
        auto operator<=>(Word const& right) const -> std::weak_ordering;

    private:
        std::string word;
    };

    inline auto operator<<(std::ostream& os, Word const& word) -> std::ostream& {
        return word.print(os);
    }

    inline auto operator>>(std::istream& is, Word & word) -> std::istream& {
        return word.readFrom(is);
    }
} // namespace text


#endif