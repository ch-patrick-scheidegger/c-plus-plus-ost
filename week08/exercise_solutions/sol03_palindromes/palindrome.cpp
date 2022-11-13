#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

auto isPalindrome(std::string const &s) -> bool {
  return equal(s.begin(),s.end(),s.rbegin(),
      [](char l, char r){
        return std::tolower(l)==std::tolower(r);
      });
}

auto main() -> int{
  std::ifstream input{"linuxwords.txt"};
  using initer=std::istream_iterator<std::string>;
  std::ostream_iterator<std::string> out{std::cout,"\n"};
  copy_if(initer{input},initer{},out,isPalindrome);
}
