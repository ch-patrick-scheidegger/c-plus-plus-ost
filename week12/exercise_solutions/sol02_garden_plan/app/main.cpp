#include "bed.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
#include "shoppingList.hpp"
#include "square.hpp"
#include "triangle.hpp"

#include <iostream>
#include <vector>
#include <memory>

auto main() -> int {
    auto beds = std::vector<std::shared_ptr<Bed>>{
        std::make_shared<Triangle>(3, 6, 6.70820393),
        std::make_shared<Triangle>(3,4,4),
        std::make_shared<Triangle>(3,4,4),
        std::make_shared<Diamond>(4, 60),
        std::make_shared<Square>(3),
        std::make_shared<Square>(3),
        std::make_shared<Rectangle>(4, 9),
    };

    printShoppingList(beds, std::cout);
}