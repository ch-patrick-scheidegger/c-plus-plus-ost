#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

namespace Games {

struct FizzBuzz {
  auto run(unsigned n, std::ostream &out) -> void {
    std::ostream_iterator<std::string> outIter{out, "\n"};
    auto gen = [this] {
      value++;
      std::string result{};
      if (value % 3 == 0) {
        result += "Fizz";
      }
      if (value % 5 == 0) {
        result += "Buzz";
      }
      if (result.empty()) {
        result = std::to_string(value);
      }
      return result;
    };
    std::generate_n(outIter, n, gen);
  }

private:
  int value{};
};

} // namespace Games

auto main() -> int {
  Games::FizzBuzz fb{};
  fb.run(15, std::cout);
}
