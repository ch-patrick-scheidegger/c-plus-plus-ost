#ifndef BED_HPP
#define BED_HPP

// TODO: Implement class bed
struct Bed {
    virtual ~Bed() = default;

    virtual auto numberOfPegs() const -> int = 0;
    virtual auto stringLength() const -> int = 0;
    virtual auto seeds() const -> int = 0;
};

#endif