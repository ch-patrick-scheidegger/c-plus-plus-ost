#include "semester.hpp"
#include "module.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>

namespace {

template <typename ModItr>
auto canBeTaken(ModulePtr module, ModItr accomplishedBegin, ModItr accomplishedEnd) -> bool {
  auto predecessors = module->predecessors();
  return std::ranges::all_of(predecessors,[&](auto m) {
    return std::find(accomplishedBegin, accomplishedEnd, m) != accomplishedEnd;
  });
}

void printPlan(Catalog const &catalog, std::ostream &out) {
  auto semester = 1u;
  auto finished = Modules{};
  auto all = values(catalog);
  auto remaining = Modules{std::begin(all), end(all)};

  while (!remaining.empty()) {
    out << semester << ": ";
    Modules current{};

    std::ranges::copy_if(remaining, std::inserter(current, std::begin(current)), [&](auto m) {
      return canBeTaken(m, begin(finished), end(finished));
    });

    std::ranges::copy(current, std::ostream_iterator<ModulePtr>{out, " "});

    std::ranges::copy(current, std::inserter(finished, std::begin(finished)));

    std::ranges::for_each(current, [&](auto m) {
      auto toRemove = std::remove(begin(remaining), end(remaining), m);
      remaining.erase(toRemove, remaining.end());
    });

    semester++;
    out << "\n";
  }
}
} // namespace

auto printSemester(std::string filename, std::ostream &out) -> void {
  auto file = std::ifstream {filename};
  auto catalog = readModules(file);
  printPlan(catalog, out);
}
