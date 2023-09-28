#include "semesterSort.hpp"
#include "module.hpp"

#include <algorithm>
#include <iterator>
#include <ostream>
#include <unordered_map>

namespace {

void depthFirst(ModulePtr m, Modules &order, std::unordered_map<ModulePtr, bool> &marked) {
  marked[m] = true;
  auto successors = m->successors();
  std::ranges::for_each(successors, [&](auto s) {
    if (!marked[s]) {
      depthFirst(s, order, marked);
    }
  });
  order.push_back(m);
}

auto topologicalOrder(Modules const &initial, Modules const &all) -> Modules {
  auto marked = std::unordered_map<ModulePtr, bool> {all.size()};
  std::ranges::for_each(all, [&](auto m) { marked[m] = false; });

  auto order = Modules{};
  std::ranges::for_each(initial, [&](auto m) {
    if (!marked[m]) {
      depthFirst(m, order, marked);
    }
  });
  return order;
}

void updateSuccessors(ModulePtr module) {
  auto successors = module->successors();
  std::ranges::for_each(successors, [&](auto s) {
    s->earliestSemester(module->earliestSemester() + 1);
  });
}

void updateEarliestSemester(Catalog const &catalog) {
  auto all = values(catalog);
  auto firstSemester = Modules{};
  std::ranges::for_each(all, [&](auto m) {
    if (!m->hasPredecessor()) {
      m->earliestSemester(1);
      firstSemester.push_back(m);
    }
  });

  auto order = topologicalOrder(firstSemester, all);
  std::for_each(std::rbegin(order), std::rend(order), [](auto m) {
    updateSuccessors(m);
  });
}

struct SemesterComparator {
  auto operator()(ModulePtr m, unsigned semester) const -> bool {
    return m->earliestSemester() < semester;
  }

  auto operator()(unsigned semester, ModulePtr m) const -> bool {
    return semester < m->earliestSemester();
  }
};

} // namespace

void printSemesterTopological(std::istream &input, std::ostream &out) {
  auto catalog = readModules(input);
  updateEarliestSemester(catalog);
  auto modules = values(catalog);
  std::ranges::sort(modules, [](auto lhs, auto rhs) {
    return lhs->earliestSemester() < rhs->earliestSemester();
  });

  auto lastSemester = (*std::rbegin(modules))->earliestSemester();

  for (auto semester = 1u; semester <= lastSemester; ++semester) {
    auto range = std::equal_range(std::begin(modules),
                                  std::end(modules),
                                  semester,
                                  SemesterComparator{});
    out << semester << ": ";
    std::copy(range.first, range.second, std::ostream_iterator<ModulePtr>{out, " "});
    out << "\n";
  }
}
