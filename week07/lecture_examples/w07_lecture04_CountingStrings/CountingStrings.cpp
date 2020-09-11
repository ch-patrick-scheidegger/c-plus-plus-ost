#include <map>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

void countStrings(std::istream & in, std::ostream & out) {
  std::map<std::string, size_t> occurrences{};
  std::istream_iterator<std::string> inputBegin{in};
  std::istream_iterator<std::string> inputEnd{};
  for_each(inputBegin, inputEnd, [&occurrences](auto const & str) {
	++occurrences[str];
  });
  for(auto const & occurrence : occurrences) {
    out << occurrence.first << " = "<< occurrence.second << '\n';
  }
}

int main(){
	countStrings(std::cin, std::cout);
}
