#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <fstream>
#include <chrono>
#include <utility>
#include <vector>

using anaset=std::multiset<char>;
using anaword=std::pair<anaset,std::string>;
using anawords=std::vector<anaword>;
using anaiter=anawords::const_iterator;
using anacand=std::vector<anaword>;
using allanas=std::vector<anacand>;
using outiter=std::ostream_iterator<std::string>;

auto printCandidate(std::ostream &out, anacand const &cand) -> void {
  // should create all permutations of cand's words
  auto sentence = std::vector<std::string>{};

  transform(begin(cand), end(cand), back_inserter(sentence), [](anaword w) {
    auto word = std::string{};
    transform(begin(w.second), end(w.second), back_inserter(word), tolower);
    return word;
  });
  copy(begin(sentence), end(sentence), outiter { out, " " });
  out << '\n';
}

auto printAllCandidates(std::ostream &out, allanas const &all) -> void {
  for (auto c : all) {
    printCandidate(out, c);
  }
}

auto makeAnaword(std::string const &words) -> anaword {
  auto s{words};
  s.erase(remove_if(begin(s), end(s), [](char c) {
    return !isalpha(c);
  }),end(s));
  transform(begin(s), end(s), begin(s), tolower);
  return make_pair(anaset { begin(s), end(s) }, words);
}

auto print(std::ostream &out, anaword w) -> void {
  auto os = std::ostream_iterator<char>{out};
  copy(begin(w.first), end(w.first), os);
  out << ": " << w.second << '\n';
}

auto subsetOfWord(anaword const &w, anaword const &aw) -> bool {
  return aw.second.size() && includes(begin(w.first), end(w.first), begin(aw.first), end(aw.first));
}

auto caselessEqual(anaword const &w, anaword const &v) -> bool {
  return equal(begin(w.second), end(w.second), begin(v.second), end(v.second), [](char l, char r) {
    return tolower(l) == tolower(r);
  });
}

auto notalreadyinSetInDifferentSpelling(anaword const &w, anawords const &wl) -> bool {
  auto b = begin(wl);
  auto e = end(wl);
  bool res = e == find_if(b, e, [w](auto v) {
    return caselessEqual(w, v);
  });
  if (!res)
    std::cout << "already there " << w.second << std::endl;
  return res;
}

auto collectFromFile(anaword w, std::string filename = "linuxwords.txt") -> anawords {
  auto wl = anawords{};
  auto allwords = std::ifstream{filename};
  auto s = std::string{};

  while (getline(allwords, s)) {
    if (s.size() > 1 || s == "I" || s == "A") {
      auto aw = makeAnaword(s);
      if (subsetOfWord(w, aw) && notalreadyinSetInDifferentSpelling(aw, wl)) {
        wl.push_back(aw);

      }
    }
  }
  return wl;
}

auto subtract(anaword const &origin, anaword const &candidate) -> anaword {
  if (subsetOfWord(origin, candidate)) {
    auto res = std::string{};
    std::set_difference(begin(origin.first), end(origin.first), begin(candidate.first), end(candidate.first), back_inserter(res));
    return makeAnaword(res);
  }
  return origin;
}

auto lookForFittingRest(anawords const &wl, anaiter b, anaiter e, anaword rest, allanas &res, anacand &cand) -> void {
  while (b != e) {
    if (subsetOfWord(rest, *b)) {
      cand.push_back(*b);
      auto newrest = subtract(rest, *b);
      if (newrest.first.size()) {
        lookForFittingRest(wl, begin(wl), e, newrest, res, cand);
      } else {
        res.push_back(cand);
      }
      cand.pop_back();
    }
    ++b;
  }
}

auto addCandidatesFor(anawords const &wl, anaiter b, anaiter e, anaword origin, allanas &res) -> void {
  while (b != e) {
    if (subsetOfWord(origin, *b)) { // should be true anyway
      auto cand = anacand{1, *b};
      auto rest = subtract(origin, *b);
      if (rest.first.size()) {
        lookForFittingRest(wl, begin(wl), e, rest, res, cand);
      } else {
        res.push_back(cand);
      }
    }
    ++b;
  }
}

auto findCandidates(anawords const &wl, anaword const &origin) -> allanas {
  auto res = allanas{};
  addCandidatesFor(wl, wl.begin(), wl.end(), origin, res);
  return res;
}

auto doAnagram(std::istream &in, std::ostream &out) -> void {
  auto word = std::string{};
  getline(in, word);
  auto w = makeAnaword(word);
  print(out, w);
  auto start = std::chrono::system_clock::now();
  auto wl = collectFromFile(w, "linuxwords.txt");
  out << wl.size() << "matching words in set" << std::endl;
  auto res = findCandidates(wl, w);
  std::chrono::duration<double> delta = std::chrono::system_clock::now() - start;
  out << res.size() << " anagrams found\n";
  out << delta.count() << "s time\n";
  getline(in, word);
  printAllCandidates(out, res);
}

auto main() -> int {
  doAnagram(std::cin, std::cout);
}
