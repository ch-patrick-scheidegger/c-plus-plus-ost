

#include <ostream>
#include <vector>

struct Meal{};
struct Step{};

struct Recipe {
  // Recipe(std::vector<Step> steps) = default;
  auto cook() const -> Meal;
private:
  std::vector<Step> steps{};
};

struct Chair {
  explicit Chair(unsigned legs = 4u);
private:
  unsigned legs;
};
Chair::Chair(unsigned legs) 
  : legs{legs} {
  if (legs < 1u) {
    throw std::invalid_argument{"..."};
  }
}
