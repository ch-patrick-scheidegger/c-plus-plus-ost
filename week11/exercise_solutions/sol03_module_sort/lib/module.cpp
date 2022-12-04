#include "module.hpp"

#include <algorithm>
#include <compare>
#include <memory>
#include <string>

Module::Module(std::string const &name) : name{name} {
}

auto Module::add(spm other) -> void {
  pre_requisites.push_back(other);
}

auto Module::done_with(spm other) -> void {
  auto found = std::remove(begin(pre_requisites), end(pre_requisites), other);
  pre_requisites.erase(found, end(pre_requisites));
}

auto Module::is_ready() const -> bool {
  return pre_requisites.empty();
}

auto Module::operator<=>(const Module &other) const -> std::strong_ordering {
  return name <=> other.name;
}

auto operator>>(std::istream & input, Module & obj) -> std::istream & {
  input >> obj.name;
  return input;
}

auto make_module(std::string name) -> Module::spm {
  return std::make_shared<Module>(name);
}
