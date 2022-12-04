#ifndef MODULE_HPP
#define MODULE_HPP

#include <compare>
#include <istream>
#include <memory>
#include <string>
#include <vector>

struct Module {
  using spm = std::shared_ptr<Module>;

  explicit Module(std::string const &name);

  auto add(spm other) -> void;

  auto done_with(spm other) -> void;

  auto is_ready() const -> bool;

  auto operator<=>(Module const &other) const -> std::strong_ordering;
  auto operator==(Module const &other) const -> bool = default;

  std::string name;
  std::vector<spm> pre_requisites;
};

auto operator>>(std::istream &input, Module &obj) -> std::istream &;

auto make_module(std::string name) -> Module::spm;

#endif
