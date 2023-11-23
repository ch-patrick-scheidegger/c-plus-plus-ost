# Function Templates

## Function Template `median()`

* Write a function template `median(a, b, c)` taking three arguments of the same type and returning the one in the middle, i.e., neither min/max.
* Provide useful unit tests for your function.

## Function Template `rotate3arguments()`

* Write a function template `rotate3arguments` taking three variables of the same type as arguments and exchanging the values, so that `a` obtains the value of `b`, `b` of `c`, and `c` of `a`.
* Provide useful unit tests for your function.

## Variadic Function Template `readln(std::istream&, ...)`

* Write a variadic function template `readln(std::istream&, ...)` that takes a variable number of reference arguments and uses `operator>>` to read in successive values from a line read from the `std::istream`.
* Create useful unit tests for your function(s). 
* **Hint:** you might need to create a second function that takes an `std::istream` and reads all values from it, whereas `readln` just reads a line and passes that line as an `std::istringstream` to the second function.
* **Variant:** You can provide an overload that is applied if the last (or only remaining) argument to read in is an `std::string` you put the remaining content of the line into it.

# Algorithms (Continued)

## Trivia

If you haven't completed it yet, this might be a good time to solve a few of the algorithm trivia exercises.

## Word Statistics

Use your class `Word` and create the following simple programs that provide the following results. 

* Remember: your `Word` class ignores case when compared and also ignores punctuation and white space. 
* Don't program your own loops. 
* Use appropriate data structures but don't store data unnecessarily.

Implement the following functions:

* `unsigned wcount(std::istream &)`: Returns the number of words in standard input
* `void nth(std::istream &, std::ostream &, unsigned nth)`: Count words and print out `nth` most frequent. Similar to the `printOccurrences` (from week 7) function, but only print the nth most frequent word (only a single word). Do not reuse exact code of `printOccurrences`, but again use the most optimal data structure and algorithms for this problem. 


## Prime Numbers (Optional)

Write a program primes that outputs prime numbers. Create a predicate function `isPrime(int)`. 

* Use that predicate to filter a vector filled with numbers from `1` to `100`. 
* Don't write your own loops but use the most fitting algorithms from the standard library (i.e., don't use `for_each()` with a lambda, when there exists a better algorithm.) 
* Can there be a solution for where even `isPrime()` is not using a hand-written loop?

Variants of your program:

* How many prime numbers do you get in the range `1..100`?
* How many in the range `1..1000`?
 


# Functor Exercises

## `wlist` Again!

You have already implemented the `wlist` programm twice (once with `std::string` (Ex4) and once with your `Word` (Ex5)). The implementation using `Word` should be rather short, only a few lines. Until now your `wlist` output contained the words in ascending order, from `a` to `z`. Modify the existing behavior in the following ways and create two new versions of `wlist`:

* Use a standard functor to change the sorting to descending order `z` to `a`
* Implement a functor that sorts the words by their length. If two words have the same length use the normal order of `Word` (ascending order). You might need to provide means for getting the size of a `Word`.


# Containers (Optional)

Extend your statistics library. Read a text from standard input line by line. While reading count the line numbers. Create a data structure that keeps each word (use your `Word` class) together with all line numbers it occurs upon. Print out a sorted list of words (one word per line), each followed by a list of the line numbers it occurs upon.

Example input:
```cpp
Hello
Hello again
Song by who?
```

Expected output:

```cpp
again 2 
by 3 
Hello 1 2 
Song 3 
who 3 
```
