#include "moduleSort.hpp"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

ModuleSort::ModuleSort(std::istream &input) {
  read(input);
}

auto ModuleSort::size() const -> std::size_t {
  return all_modules.size();
}

auto ModuleSort::read(std::istream &input) -> void {
  for (auto line = std::string{}; std::getline(input, line);) {
    auto stream = std::istringstream{line};
    if (auto name = std::string{}; stream >> name) {
      auto current = insert_or_update_module(name);
      while (stream >> name) {
        auto dep = insert_or_update_module(name);
        current->add(dep);
      }
    }
  }
}

auto ModuleSort::insert_or_update_module(const std::string &name) -> Module::spm {
  auto current = make_module(name);
  auto mod_it = all_modules.find(current);
  if (mod_it != all_modules.end()) {
    current = *mod_it;
  } else {
    all_modules.insert(current);
  }
  return current;
}

auto ModuleSort::next_level() -> level_result {
  auto result = std::vector<Module::spm>{};

  std::ranges::copy_if(all_modules, std::back_inserter(result), [](auto const &p) { return bool(p) && p->is_ready(); });

  for (auto p : result) {
    for (auto m : all_modules) {
      if (m)
        m->done_with(p);
    }
    all_modules.erase(p);
  }

  std::ranges::sort(result, DeepNameCompare{});
  return result;
}

auto printSemesterTopological(std::istream &input, std::ostream &out) -> void {
  auto sorter = ModuleSort{input};
  auto level = 1u;

  auto outputIterator = std::ostream_iterator<std::string>{out, " "};
  while (sorter.size()) {
    auto res = sorter.next_level();
    out << level++ << ": ";
    std::ranges::transform(res, outputIterator, [](auto p) {
      return p ? p->name : "";
    });

    out << '\n';
  }
}
