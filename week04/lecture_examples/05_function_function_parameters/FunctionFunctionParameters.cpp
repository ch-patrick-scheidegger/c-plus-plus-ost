#include <cmath>
#include <functional>
#include <iostream>

// auto applyAndPrint(double x, auto f(double) -> double) -> void {
//   std::cout << "f(" << x << ") = " << f(x) << '\n';
// }

auto applyAndPrint(double x, std::function<auto(double) -> double> f) -> void {
  std::cout << "f(" << x << ") = " << f(x) << '\n';
}


auto main() -> int {
  applyAndPrint(25, ::sqrt);

  double factor{3.0};
  auto const multiply = [factor](double value) {
    return factor * value;
  };
  applyAndPrint(1.5, multiply);

  applyAndPrint(2, [](double value){return value * value;});
}
