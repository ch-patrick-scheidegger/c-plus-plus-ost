#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <iostream>

auto main(int argc, char **argv) -> int {
  auto long_months = std::vector<std::string>{ "Jan", "Mar", "May", "Jul", "Aug", "Oct", "Dec" };
  auto accumulated_string = std::accumulate(
      begin(long_months) + 1, //Second element
      end(long_months),       //End
      long_months.at(0),      //First element, usually the neutral element
      [](std::string const & acc, std::string const & element) {
        return acc + ", " + element;
      });
  std::cout << accumulated_string; //Jan, Mar, May, Jul, Aug, Oct, Dec
}
