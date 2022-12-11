#include "shoppingList.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>

struct ShoppingData
{
    double ropes;
    double seeds;
    unsigned pegs;
};

auto printShoppingList(std::vector<std::shared_ptr<Bed>> beds, std::ostream & output) -> void {
    auto data = ShoppingData{};

    std::ranges::for_each(beds, [&](auto bed){
        data.ropes += bed->ropes();
        data.seeds += bed->seeds();
        data.pegs += bed->pegs();

        bed->print(output);
        output << '\n';
    });

    output << "pegs needed: " << data.pegs << '\n'
           << "seeds needed: " << data.seeds << " kg\n"
           << "rope needed: " << data.ropes << " m";
}
