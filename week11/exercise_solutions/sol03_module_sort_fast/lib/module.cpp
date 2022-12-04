#include "module.hpp"

#include <algorithm>

#include <iterator>
#include <memory>
#include <sstream>
#include <string>

auto getModulePtr(std::string const &module_name, Catalog &catalog) -> ModulePtr {
  if (catalog.count(module_name) == 0) {
    auto m = std::make_shared<Module>(module_name);
    catalog[module_name] = m;
  }

  return catalog[module_name];
}

auto add(Catalog &catalog, std::string const &line) -> void {
  auto line_stream = std::stringstream{line};
  auto module_name = std::string{};
  line_stream >> module_name;
  if (module_name.empty()) {
    return;
  }

  auto module = getModulePtr(module_name, catalog);
  std::for_each(std::istream_iterator<std::string>{line_stream},
                std::istream_iterator<std::string>{},
                [&](auto const &module_name) {
                  auto dependency = getModulePtr(module_name, catalog);
                  module->addPredecessor(dependency);
                });
}

auto readModules(std::istream &input) -> Catalog {
  auto catalog = Catalog{};

  for (auto line = std::string{}; getline(input, line);) {
    add(catalog, line);
  }

  return catalog;
}
