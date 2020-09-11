#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>

int main() {
  std::unordered_set<char> const vowels{'a', 'e', 'i', 'o', 'u'};
  using in = std::istreambuf_iterator<char>;
  using out = std::ostreambuf_iterator<char>;
  remove_copy_if(in{std::cin}, in{}, out{std::cout},
    [&](char c) { return vowels.count(c); }
  );
}
