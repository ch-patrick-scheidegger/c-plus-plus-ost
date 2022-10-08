
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>



// auto intsUpTo(std::size_t from = 0,                      
//               std::size_t to) -> std::vector<int> {
//   //ensure to >= from
//   std::vector<int> values(to – from + 1);
//   std::iota(values.begin(), values.end(), from);
//   return values;
// }


// ---------------------

auto square(int x, void print(int)) -> void {
  print(x * x);
}

auto main() -> int {
  auto p = [](auto value) {
    std::cout << value;
  };
  square(5, p);
}
