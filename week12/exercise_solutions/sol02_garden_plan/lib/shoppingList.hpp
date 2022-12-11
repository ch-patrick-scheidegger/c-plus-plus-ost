#ifndef SHOPPING_LIST_HPP
#define SHOPPING_LIST_HPP

#include "bed.hpp"

#include <iosfwd>
#include <memory>
#include <vector>

auto printShoppingList(std::vector<std::shared_ptr<Bed>> beds, std::ostream & output) -> void;

#endif