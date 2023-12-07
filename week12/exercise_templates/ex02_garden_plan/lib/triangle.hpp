#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "bed.hpp"

// TODO: Implement class triangle
class Triangle : Bed {

    virtual auto numberOfPegs() const -> int override;
    virtual auto stringLength() const -> int override;
    virtual auto seeds() const -> int override;
};


#endif
