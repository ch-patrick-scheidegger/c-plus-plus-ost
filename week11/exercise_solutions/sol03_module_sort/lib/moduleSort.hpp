#ifndef MODULE_SORT_HPP
#define MODULE_SORT_HPP

#include "module.hpp"

#include <cstddef>
#include <iosfwd>
#include <set>
#include <string>
#include <vector>

struct DeepNameCompare {
  auto operator()(Module::spm const &lhs, Module::spm const &rhs) const -> bool {
    if (lhs && rhs) {
      return *lhs < *rhs;
    }
    return (!lhs && rhs);
  }
};

using level_result = std::vector<Module::spm>;

struct ModuleSort {
  explicit ModuleSort(std::istream &input);

  auto size() const -> std::size_t;

  auto read(std::istream &input) -> void;

  auto insert_or_update_module(const std::string &name) -> Module::spm;

  auto next_level() -> level_result;

  std::set<Module::spm, DeepNameCompare> all_modules;
};

auto printSemesterTopological(std::istream &input, std::ostream &out) -> void;

#endif
