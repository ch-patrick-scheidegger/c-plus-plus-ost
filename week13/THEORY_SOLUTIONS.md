# 0 Initialization

```cpp
#include <array>
#include <vector>
#include <iostream>

std::array<char const *, 4> names{{"Freely", "Cally", "Sofieus", "Avren"}}; // Aggregate Initialization

void print_names(std::ostream & out) {
  std::size_t name_count; // Default Initialization
  name_count = names.size(); // NONE! Copy Assignment

  for(int i = 0; i < name_count; ++i) { // Copy Initialization
    std::string name{names[i]}; // List Initialization
    out << name << '\n';
  }
}

int main() {
  std::size_t name_count(names.size()); // Direct Initialization

  std::cout << "will print " << name_count << " names\n";

  print_names(std::cout);
}
```
