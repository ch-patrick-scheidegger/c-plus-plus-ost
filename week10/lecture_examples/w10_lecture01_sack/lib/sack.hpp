#ifndef SACK_HPP_
#define SACK_HPP_

#include <initializer_list>
#include <random>
#include <stdexcept>
#include <vector>

template <typename T> class Sack {
  using SackType = std::vector<T>;
  using size_type = typename SackType::size_type;
  SackType theSack{};

  inline static std::mt19937 randengine{};
  using rand = std::uniform_int_distribution<size_type>;

public:
  // Rule of 5
  Sack() = default;
  Sack(Sack const &) = default;
  Sack(Sack &&) = default;
  auto operator=(Sack const &) -> Sack & = default;
  auto operator=(Sack &&) -> Sack & = default;

  explicit Sack(std::initializer_list<T> list)
    : theSack(list) {
  }

  auto empty() const -> bool {
    return theSack.empty();
  }

  auto size() const -> size_type {
    return theSack.size();
  }

  auto putInto(T const &item) -> void {
    theSack.push_back(item);
  }

  // Defined out-of-line as an example
  auto getOut() -> T;

  template <typename Elt = T> explicit operator std::vector<Elt>() const {
    return std::vector<Elt>(theSack.begin(), theSack.end());
  }
};

template <typename T>
inline auto Sack<T>::getOut() -> T {
  if (empty()) {
    throw std::logic_error{"empty Sack"};
  }

  auto index = rand{0u, size() - 1}(randengine);
  auto retval{theSack.at(index)};
  theSack.erase(theSack.begin() + index);
  return retval;
}

template <typename T>
auto makeSack(std::initializer_list<T> list) -> Sack<T> {
  Sack<T> sack;
  for (auto it = list.begin(); it != list.end(); ++it)
    sack.putInto(*it);
  return sack;
}

template <typename T>
struct Sack<T *> {
  ~Sack() = delete;
};

template <>
struct Sack<char const *> : Sack<std::string>{
  using Sack<std::string>::Sack;
};

#endif
