#ifndef MODULE_HPP
#define MODULE_HPP

#include <algorithm>
#include <iosfwd>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct Module;

using ModulePtr = std::shared_ptr<Module>;
using Modules = std::vector<ModulePtr>;
using Catalog = std::map<std::string, ModulePtr>;

struct Module : std::enable_shared_from_this<Module> {
  Module() = default;
  explicit Module(std::string const &name) : name{name} {};

  void addPredecessor(ModulePtr predecessor) {
    _predecessors.push_back(predecessor);
    predecessor->_successors.push_back(shared_from_this());
  }

  auto hasPredecessor() const -> bool { return !_predecessors.empty(); }

  void earliestSemester(unsigned newEarliestSemester) {
    earliest_semester = std::max(newEarliestSemester, earliest_semester);
  }

  auto earliestSemester() const -> unsigned { return earliest_semester; }

  auto successors() const -> Modules { return _successors; }

  auto predecessors() const -> Modules { return _predecessors; }

  std::string const name;

private:
  unsigned earliest_semester{0};
  std::vector<ModulePtr> _predecessors{};
  std::vector<ModulePtr> _successors{};
};

inline auto operator<<(std::ostream &out, ModulePtr m) -> std::ostream & {
  out << m->name;
  return out;
}

auto readModules(std::istream &input) -> Catalog;

template <typename M>
inline auto values(M const &catalog) -> std::vector<typename M::mapped_type> {
  std::vector<typename M::mapped_type> values{};
  std::transform(
      std::begin(catalog), std::end(catalog), std::back_inserter(values),
      [](typename M::value_type const &pair) { return pair.second; });
  return values;
}

#endif
