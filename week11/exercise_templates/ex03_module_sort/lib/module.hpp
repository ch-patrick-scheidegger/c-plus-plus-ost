#ifndef MODULE_HPP
#define MODULE_HPP

#include <compare>
#include <memory>
#include <string>
#include <vector>

class Module {
public:
    Module(std::string name) : name{name} {};

    auto operator<=>(Module const & right) -> std::strong_ordering {
        if(right.dependingOn.size() == dependingOn.size()){
            return name <=> right.name;
        }
        return right.dependingOn.size() <=> dependingOn.size();
    }

    std::string name;
    std::vector<std::shared_ptr<Module>> dependingOn {};
};

#endif