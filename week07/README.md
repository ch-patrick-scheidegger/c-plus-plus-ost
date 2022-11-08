# Applications of `std::map` and `std::set`

In this exercise you will facilitate an associative container to create a histogram of `Word` (your own `Word` class) objects and use an `std::set` to create a sorted occurrence structure.

## Preparation - Move `Word` to namespace `text`

In this exercise (and also on ALF) we expect your `Word` class to be located in the `text` namespace. If your `Word` class is not already located in that namespace, adapt your implementation according to this requirement.

## Histogram Function

Create the header and source files `Statistics.hpp` and `Statistics.cpp` featuring a namespace `statistics`. In these files implement a function `histogram` that counts `Word` occurrences on an `std::istream` and creates an `std::map` with the `Word` as key and the count of type `int` as value:

```cpp
namespace statistics {

auto histogram(std::istream&) -> std::map<Word, int>;

}
```

Example input:

```
Wenn hinter Fliegen Fliegen fliegen, fliegen Fliegen Fliegen nach.
```

Expected content of the `std::map`:

```
Fliegen: 6
hinter: 1
nach: 1
Wenn: 1
```


## `HistogramEntry` Class

As preparation for the next step implement a helper class `HistogramEntry`, which will be used as element type for `std::set` later. It is a class that contains the `Word` and its number of occurrences. In order to use this type in an `std::set` and to print them you should implement the following operators:

* Comparison operations: `<`, `>`, `<=`, `>=`, `==` and `!=` (provided by implementing `<=>` and `==`)
* The semantics of the `<` operator should be that a `HistogramEntry` is less than if the occurrence count is larger, or if the count is equal the `<` comparison of `Word` is used.

```cpp
HistogramEntry books{Word{"Book"}, 2};
HistogramEntry cups{Word{"Cup"}, 2};
HistogramEntry pens{Word{"Pen"}, 1};

// books < cups
// books < pens
// cups < pens
```

* Output operator for `std::ostream`: `<<`

```cpp
HistogramEntry sheets{Word{"Sheet"}, 5};
std::cout << sheets; //prints: Sheet: 5
```


## Find Top N Elements

Implement a function `top` in the `statistics` namespace that prints the `n` most frequent `Word`s given a histogram-`map` from above. Signature for `top`:

```cpp
auto top(std::map<Word, int> const& occurrences, int n) -> std::set<HistogramEntry>;
```

**Note:**
* If number of elements in `occurrences` is less than `n` all elements are contained in the result.
* To get from `std::map` entries to `HistogramEntry`s you can use `std::ranges::for_each` or sneak-peek at `std::ranges::transform` and `std::inserter`. We will cover them next week.


## Print Top N Elements

Implement a function `printOccurrences` that takes an `std::istream`, an `std::ostream` and an `int n`. It reads the words from the `std::istream` and prints the `n` most frequent words and their number of occurrence on the `std::ostream`.

```cpp
auto printOccurrences(std::istream &, std::ostream &, int n) -> void;
```

# Solution

*Note:* All test cases and solution parts are commented out as the required `Word` class is not in the repository.
