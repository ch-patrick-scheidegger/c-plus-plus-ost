#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>


auto main() -> int{
  auto out = std::ostream_iterator<int>{std::cout, ", "};
  auto odd = std::set{1, 5, 7, 3, 9};
  auto even = std::set{2, 8, 6, 4, 10};
  auto all = std::vector<int>{};
  merge(begin(odd), end(odd), begin(even), end(even), std::back_inserter(all));
  copy(begin(all), end(all), out);
}
