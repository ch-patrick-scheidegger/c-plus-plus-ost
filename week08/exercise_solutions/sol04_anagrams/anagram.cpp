#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>

using analist = std::set<std::string>;
using outiter=std::ostream_iterator<std::string>;
using initer=std::istream_iterator<std::string>;

auto makeAnagrams(std::string s) -> analist{
  sort(s.begin(),s.end());
  auto anagrams = analist{};
  anagrams.insert(s);
  while(std::next_permutation(s.begin(),s.end())){
    anagrams.insert(s);
  }
  return anagrams;
}

auto outputRealWordsWithLambda(outiter out,analist const &list) -> void{
  auto allwords = std::ifstream{"linuxwords.txt"};
  auto input = initer{allwords};
  copy_if(input,initer{},out,[&list](std::string const& s){return list.count(s);});
}

auto main() -> int{
  auto word = std::string{};
  std::cin >> word;
  auto list = makeAnagrams(word);
  auto out = outiter{std::cout,"\n"};
  copy(list.begin(),list.end(),out);
  std::cout << "--------------------------\n";
  outputRealWordsWithLambda(out,list);
}
