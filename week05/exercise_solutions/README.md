No solutions for the `Word` class because it will be aprt of the next testat.

# `wlist` with `Word`

The solution becomes much simpler, as the `Word` class already takes care of the caseless sorting. This features is used by the `std::set` to only contain unique words in ascending order.

```cpp
#include "Word.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

int main() {
	using in = std::istream_iterator<std::string>;
	std::set<Word> wlist{in{std::cin}, in{}};
	copy(begin(wlist), end(wlist), std::ostream_iterator<std::string>{std::cout,"\n"});
}
```
