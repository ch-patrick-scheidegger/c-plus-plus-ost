No solutions for the `Word` class because it will be a part of the next testat.

# `wlist` with `Word`

The solution becomes a little simpler, as the `Word` class already takes care of the caseless sorting. This features is used by the `std::set` to only contain unique words in ascending order.

```cpp
auto wlist_caseless(std::istream &input, std::ostream &output) -> void {
  using in = std::istream_iterator<Word>;
  std::set<Word> wlist{in{input}, in{}};
  std::ranges::copy(wlist, std::ostream_iterator<Word>{std::cout,"\n"});
}
```
