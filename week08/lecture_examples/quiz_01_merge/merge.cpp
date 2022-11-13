#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>


int main() {
  std::ostream_iterator<int> out{std::cout, ", "};
  std::set odd{1, 5, 7, 3, 9};
  std::set even{2, 8, 6, 4, 10};
  std::vector<int> all{};
  merge(begin(odd), end(odd), begin(even), end(even), std::back_inserter(all));
  copy(begin(all), end(all), out);
}
