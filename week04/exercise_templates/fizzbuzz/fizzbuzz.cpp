#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

namespace Games {

struct FizzBuzz {
  void run(unsigned n, std::ostream & out) {
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

}

int main(int argc, char **argv) {
  Games::FizzBuzz fb{};
  fb.run(15, std::cout);
}
