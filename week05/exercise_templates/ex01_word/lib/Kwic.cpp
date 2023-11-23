
#include "Kwic.hpp"
#include "Word.hpp"

#include <algorithm>
#include <istream>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

namespace text {

    using Line = std::vector<text::Word>;

    auto getWordsOfLine(std::istream& in) -> Line {
        Line result{};
        while(in.good()){
            Word word{};
            word.readFrom(in);
            if(!in.fail()) {
                result.push_back(word);
            }
        }
        return result;
    }

    auto getKwicResult(std::vector<Line> lines) -> std::set<Line> {
        std::set<Line> kwicResult{};
        std::ranges::for_each(lines, [&kwicResult](auto line) {
            std::ranges::for_each(line, [&kwicResult, &line](auto _) {
                kwicResult.insert(line);
                std::rotate(line.rbegin(), line.rbegin() + 1, line.rend());
            });
        });
        return kwicResult;
    }

    auto printOnSeparateLines(std::ostream& out, std::set<Line> kwicResult) -> void {
        std::ranges::for_each(kwicResult, [&out](auto line){
            std::ranges::for_each(line, [&out](auto word){
                out << word << " ";
            });
            out << '\n';
        });
    }

    void kwic(std::istream& in, std::ostream& out) {
        std::string line{};
        std::vector<Line> lines{};
        while (std::getline(in, line)) {
            std::istringstream is{line};
            lines.push_back(getWordsOfLine(is));
        }
        auto kwicResult = getKwicResult(lines);
        printOnSeparateLines(out, kwicResult);
    }

} // namespace text