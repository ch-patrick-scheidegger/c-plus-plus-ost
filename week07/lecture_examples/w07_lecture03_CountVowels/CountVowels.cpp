#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>

void countVowels(std::istream &in, std::ostream &out) {
	std::map<char, size_t> vowels { { 'a', 0 }, { 'e', 0 }, { 'i', 0 }, { 'o', 0 }, { 'u', 0 }, { 'y', 0 } };
	char c { };
	while (in >> c) {
		if (vowels.count(c)) { // only count those chars that are already in the map
			++vowels[c];
			for_each(cbegin(vowels), cend(vowels), [&out](auto const &entry) {
				// entry is a pair<char, size_t>
				out << entry.first << " = " << entry.second << '\n';
			});
		}
	}
}

int main() {
	countVowels(std::cin, std::cout);
}
