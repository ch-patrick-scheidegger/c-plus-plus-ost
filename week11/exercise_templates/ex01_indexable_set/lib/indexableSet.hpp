#ifndef INDEXABLE_SET_HPP
#define INDEXABLE_SET_HPP

#include <functional>
#include <set>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <format>

template <typename T, typename COMPARE=std::less<T>>
class IndexableSet : public std::set<T,COMPARE> {
public:
    using container = std::set<T,COMPARE>;
    using const_reference = typename container::const_reference;
    // include constructors
    using container::container;

    auto operator[](auto index) -> const_reference {
        return getElement(index);
    }

    auto at(auto index) -> const_reference {
        if((index >= 0 && index >= this->size()) || (index < 0 && -index > this->size())) {
            throw std::out_of_range{std::format("Index {} is out of range", index)};
        }
        return getElement(index);
    }

    auto front() -> T {
        if(this->size() == 0) {
            throw std::out_of_range{"Set is empty"};
        }
        return *this->cbegin();
    }

    auto back() -> T {
        if(this->size() == 0) {
            throw std::out_of_range{"Set is empty"};
        }
        return *this->crbegin();
    }

private:
    auto getElement(auto index) -> const_reference {
        auto iter = this->cbegin();
        if(index < 0) {
            index += this->size();
        }
        std::advance(iter, index);
        return *iter;
    }
};

#endif