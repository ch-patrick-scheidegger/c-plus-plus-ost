#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "bed.hpp"
#include <stdexcept>


// TODO: Implement class square
class Square : Bed {
public:
    Square(int length) : Bed{}, length{length} {
        if(length <= 0) {
            throw std::invalid_argument("Length must be greater equal 0");
        }
    }

    virtual auto numberOfPegs() const -> int override;
    virtual auto stringLength() const -> int override;
    virtual auto seeds() const -> int override;

private:
    int length;
};

#endif
