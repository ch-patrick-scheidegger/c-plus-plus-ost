# Algorithm Trivia

I guess you're getting bad feeling by now if you still haven't complete all algorithm trivia task. It is a fun exercise (some claim), so you might want to get started with them as warm up.


# 0 Initialization

Given the following piece of code, name the forms of initialization used:

```cpp
#include <array>
#include <vector>
#include <iostream>

std::array<char const *, 4> names{{"Freely", "Cally", "Sofieus", "Avren"}};

auto print_names(std::ostream & out) -> void {
  std::size_t name_count;
  name_count = names.size();

  for(auto i = 0; i < name_count; ++i) {
    std::string name{names[i]};
    out << name << '\n';
  }
}

auto main() -> int {
  std::size_t name_count(names.size());

  std::cout << "will print " << name_count << " names\n";

  print_names(std::cout);
}
```

# 1 Phone Book

Implement a simple header-only phone-book type library.
Write the following types:

* `Address` with the fields `zipCode`, `city`, `street`, `streetNumber`
* `Person` with the fields `firstName`, `lastName`
* `Entry`, representing a simple phone-book entry with the following fields: `person`, `address`, `phoneNumber`.

Implement all three types as aggregates.
Use appropriate types for the respective fields.
Make sure an `Entry` can be printed on the console (implement the required support functionality in `Address` and `Person`).
Test your implementation using suitable unit tests.
