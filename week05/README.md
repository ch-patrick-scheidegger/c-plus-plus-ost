# 0 Catch Up
Chances are high that you haven't been able to solve all exercises from last week. So first complete the remaining non-extra exercises from ExW4


# 1  A value class for Words (This will be required for next Testat!)

Create a class **Word** that represents a **single** word. 

*  It can be input with `>>` and output with `<<` (from `std::istream` and to `std::ostream`). 
*  When input, a word will only consist of letters (`std::isalpha(c)`). Any other character terminates the word. You have to ignore all leading non-alpha characters, like white-space, digit or punctuation. 
*  You either need to implement the input `>>` and output `<<` operators as `friend` functions in the `word` class or you have to add `read(std::istream &)` and `write(std::ostrem&)` as member functions of your class `Word`. Then the I/O operator functions can be implemented delegating to these member functions in `Word.hpp`.

**Example:** 
An `std::istream` containing the sequence `"compl33tely ~ weird !!?!! 4matted in_put"` would result in six Words ("compl", "tely", "weird", "matted", "in", "put"). Each call of the input operator reads one word.
```cpp
std::istringstream input{"compl33tely ~ weird !!?!! 4matted in_put"};
Word w{};
input >> w;
//Now word contains "compl"
input >> w;
//Now word contains "tely"
input >> w;
//Now word contains "weird"
input >> w;
//Now word contains "matted"
input >> w;
//Now word contains "in"
input >> w;
//Now word contains "put"
input >> w;
//Now the stream should be in fail state and w should still contain "put"
```

*  You do not accept empty words, so you continue reading until a word has at least one alphabetical character.
  *  When constructing a word without an argument use some valid content as default.

*  You can also construct words from `std::string` but guarantee the invariant that it only consists of alphabetical characters. Subsequently, if that constructor is called with an `std::string` containing invalid characters, prevent the Word object from being constructed.

*  Words might be used as entries in a dictionary, so they compare with each other IGNORING letter case. Provide the corresponding infrastructure for ALL relational operators.

Write CUTE unit tests for all behavior your word class shows!

Write a test that checks what happens at the end of the input with the input stream. Will an empty word be created, even if it is forbidden?

**Hints:** 

*  The exercise template some ideas for tests (not necessarily complete).
*  Constructors callable with a single argument should be `explicit`
*  Avoid creating a case-less intermediate string representation of the word content for comparison.
*  You will need some means to avoid reading over the end of the word on a stream (check the `peek()` member function of `std::istream`).
*  Implement all non-operator member functions in the source-file.
*  Do **NOT** create a `getter` or `setter` member function, keep the encapsulation.


## 2 `wlist` revisited using `Word` (Will not be part of the testat)

Based on this class Word, implement the exercise **wlist** from last week ExW4 with this class. How does the program become simpler with your library class instead of using `std::string` (it should)?



