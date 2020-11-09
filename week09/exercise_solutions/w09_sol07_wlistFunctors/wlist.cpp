#include "word.h" //use your word.h Header

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>

struct WordLengthComparator {
	bool operator()(text::Word const & lhs, text::Word const & rhs) const {
		auto lhsContent = wordToString(lhs);
		auto rhsContent = wordToString(rhs);
		return lhsContent.length() < rhsContent.length() || (lhsContent.length() < rhsContent.length() && lhs < rhs);
	}
private:
	static std::string wordToString(text::Word const & word) {
		std::ostringstream wordContent{};
		wordContent << word;
		return wordContent.str();
	}
};

void wlist(std::istream & in, std::ostream & out) {
	using inIter = std::istream_iterator<text::Word>;

//	std::set<text::Word, std::greater<>> words{inIter{in}, inIter{}};
	std::set<text::Word, WordLengthComparator> words{inIter{in}, inIter{}};
	copy(begin(words),end(words),
		 std::ostream_iterator<text::Word>{out, "\n"});
}

int main() {
	wlist(std::cin, std::cout);
}

