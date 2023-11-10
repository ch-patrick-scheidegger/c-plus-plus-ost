
#include "Kwic.hpp"
#include "Word.hpp"

#include <algorithm>
#include <istream>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

namespace text {

    auto getWordsOfLine(std::istream& in) -> std::vector<text::Word> {
        std::vector<text::Word> result{};
        while(in.good()){
            Word word{};
            word.readFrom(in);
            result.push_back(word);
        }
        return result;
    }

    auto getKwicResult(std::vector<std::vector<text::Word>> linesOfWords) -> std::set<std::vector<text::Word>> {
        std::set<std::vector<text::Word>> kwicResult{};
        std::for_each(begin(linesOfWords), end(linesOfWords), [&kwicResult](auto lineOfWords) {
            for(int i = 0; i < lineOfWords.size(); i++) {
                kwicResult.insert(lineOfWords);
                std::rotate(lineOfWords.rbegin(), lineOfWords.rbegin() + 1, lineOfWords.rend());
            }
        });
        return kwicResult;
    }

    auto printOnSeparateLines(std::ostream& out, std::set<std::vector<text::Word>> kwicResult) -> void {
        std::ranges::for_each(kwicResult, [&out](auto line){
            std::ranges::for_each(line, [&out](auto word){
                out << word << " ";
            });
            out << '\n';
        });
    }

    void kwic(std::istream& in, std::ostream& out) {
        std::string line{};
        std::vector<std::vector<text::Word>> linesOfWords{};
        while (std::getline(in, line)) {
            std::istringstream is{line};
            linesOfWords.push_back(getWordsOfLine(is));
        }
        auto kwicResult = getKwicResult(linesOfWords);
        printOnSeparateLines(out, kwicResult);
    }

    void kwicTest(std::istream& in, std::ostream& out) {
        std::string line{"A B C"};
        std::vector<std::vector<text::Word>> linesOfWords{};
        std::istringstream is{line};
        linesOfWords.push_back(getWordsOfLine(is));
        auto kwicResult = getKwicResult(linesOfWords);
        printOnSeparateLines(out, kwicResult);
    }

} // namespace text