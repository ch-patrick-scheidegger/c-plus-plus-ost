**Note:** We recognized many symbol resolution issues when working with `clangd` on Windows. We recommend installing and using `clangd` from MSYS instead of the language server downloaded by the `clangd` extension. Alternatively, you could also install MSVC. We extended the [setup instructions page](https://gitlab.ost.ch/cxx/cpl/-/wikis/Setup-Development-Environment-(VSCode)#missing-standard-library-with-clangd) accordingly.

# 1. Questions about the Lecture

  - Please figure out, in which standard header file the following elements of `namespace std` are declared. Also point out, if it is a variable, function or type. Please note, in a concrete compiler implementation the exact place might be in another header file than the official standard one. You should provide the latter. Consult provided online references, if in doubt and to check your answers. Maybe your IDE can support this exploration (experiment with CTRL-click). If there is a difference in the position where the element is defined and the standard documentation give both headers and try to explain it!
    - `std::cin`
    - `std::endl`
    - `std::tolower`
    - `std::string`
    - `std::distance`
    - `std::istream_iterator`
    - `std::size_t`
    - `std::vector`




  - What are the types of the following literals:
    - `45`
    - `0XDULL`
    - `5.75`
    - `.2f`
    - `"string"`
    - `' '`



  - What is the state (`failbit`, `eofbit`, `badbit`) of the of the input stream `std::cin` after reading into `i` in the following code? For the inputs below:
    - `10`
    - `a`
    - `<no input>`

```cpp
  int i{};
  std::cin >> i;
  //...
```

---

**Important:** For all exercises working with standard input (`std::cin`) you might want to terminate the input stream. You should be able to do this on Windows with `ctrl-z` and on Unix-like systems with `ctrl-d`.

If any program you run ends up in an infinite loop, you should be able to terminate it with `ctrl-c`.

---


# 2. Simple calculator (**future testat hand in!**)

**Note:** For the testat you can and should work in groups of up to three students.

In this exercise you will...

  - implement a function for performing different operations on function parameters and return the result.
  - read formatted input from an `std::istream`
  - split a project containing an implementation and tests into tree projects: `library` (with implementation), `tests` and `executable`.


## a) Implement a `calc()` function

Create a function with the signature `auto calc(int, int, char) -> int` that takes two numbers an a character denoting an operator symbol (`'+'`, `'-'`, `'*'`, `'/'` and `'%'`). The function `calc` should interpret the operator character and compute its result by combining the two integers accordingly. To give you a headstart we have prepared one CUTE test in `CalcTest.cpp`. Add additional test cases for the corner cases of the function. Consider and test valid and invalid input, e.g. unknown operators and division by zero. What options for error handling are feasible? Discuss them with your supervisor and your peers.


```cpp
#include "Calc.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(testOnePlusOne) {
  auto result = calc(1, 1, '+');
  ASSERT_EQUAL(2, result);
}

auto createCalcSuite() -> cute::suite {
  cute::suite calcSuite{
    testOnePlusOne,
  };
  return calcSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto calcSuite = createCalcSuite();
  bool suiteResult = runner(calcSuite, "Calc Suite");

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

Hint for the implementation: Consider using a switch statement in the `calc` function.

## b) Extension: Simple calculator with stream input (future hand in)

Extend your simple calculator from above and create an additional function `auto calc(std::istream& in) -> int` that will read a number, an operator character and another number from the `istream` `in` and compute the result of the operation. E.g. `1 + 1` results in `2`. Also provide unit tests for this new calculator. 

When tests for a function taking an `std::istream &` as argument, you have to create an `std::istringstream` that contains the given input.

```cpp
TEST(testCalcWithStream) {
  std::istringstream input{"95/5"};
  auto result = calc(input);
  //...
}
```

## c) (Optional) Extension: Implement an application

If you like you can use the second `calc()` overload to implement the calculation app. We have already added an empty `main()` function and set up the project.

---


# 3. Counting Input Elements
In this exercise you will...

  - implement various character counting algorithms.
  - use the input operator (`>>`) to read different types from `std::istream`.
  - figure out how when the input operator (`>>`) skips white-space characters and how to avoid that skipping.

**Hints:**

  - Please consult your C++ reference on `iostreams` to figure out which member function to use, if the input operator `>>` doesn’t help with solving the problem. 
  - You should use an `std::istringstream` to provide your input from in test cases.
  - Do not forget to write unit tests for the following cases:
    - How does your functional core behave with empty input? 
    - Do you always get the result you are expecting?
  - Try not to store too much of the input
  - We have prepared an exercise template with library, executables and tests.
  - Do not write any fancy "UI", so that you can use your programs also as filters within a shell-pipeline.


## a) charc: Count non-whitespace char
 
Write a function `auto charc() -> unsigned` to count non-whitespace char values by reading from an input stream (`std::istream)`). The result should be the number of characters found in the stream.

```cpp
auto charc(std::istream & input) -> unsigned {
  //Your implementation of charc
}
```

**Example:** if you call the `charc()` function with a stream containing the characters `Hello, world!`, the function should return `12`.

Please note, that the input `operator >>` always skips white space characters such as blank, tab and newline.

## b) allcharc: Count all characters
 
Create a function `allcharc()` with the same signature as `charc()`. The `allcharc()` function must not skip white-space characters when counting.

**Hints:**

  -  You might need to use a member function of `std::istream` to achieve that.
  -  You should first write test cases for your new function, before implementing the function!


**Question:** Can you find other means (than the member function of `std::istream`) to NOt SKIP White Space?

## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from standard input.

**Hint:** There are several means to achieve that, for example, count the characters matching the newline character `'\n'`, or, use the `getline()` function and count how often you can call it until you reach the end of the input.


---


# 4. Experiments (see also lecture code)
 
In this exercise you will...

  - experience an example of undefined behavior, i.e. the evaluation order function arguments.
  - figure out the precedence of operators.
  - experiment with invalid input in `std::istream`


## a) Experiment: unspecified sequence
 
Experiment with the `bad_greeting.cpp` from the lecture material. It features a second string parameter on `sayGreeting()`. It is called with `inputName()` supplying each argument. What happens? Is the sequence of words the same as you entered it? Is the program safe to use? 

## b) Experiment: output with conditional operator
 
What happens if the following piece of code gets compiled and executed as part of a main function? 

```cpp
#include <iostream>

auto main() -> int {
    bool cond{};
    std::cout << cond ? "Hello" : "Peter";
}
```

Can you explain your observation? Can you fix the code to get what one might expect.

**Hint:** [CPPReference](http://en.cppreference.com/w/cpp/language/operator_precedence) might help.

## c) Questions/Experiments on input behavior

  - What happens if a user provides an invalid number to `std::cin >> anAnswer;`? Can the program continue to read further numbers?
  - How can you read a `std::string name` with the code `std::cin >> name;` if the name provided consists of several words? How can you read the rest of the input into the string variable?
  - Look at declaration of `std::getline()` function and explain its parameter passing. Why is the `std::string` parameter passed as reference?


---

# 5. Optional exercises (also for self-study)

## a) Sum numbers
 
Write a program `sumi()` to sum up a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are given. Print the resulting sum on standard output.

Example: Input `0 55 222 41 11` should result in `329`

Once you are done, change your program to accept floating point numbers instead (`sumf`). How many places do you need to change?


## b) Average numbers
 
Write a program `averagei()` to calculate the average of a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are provided. Return the resulting average on standard output.

Example, integrated into a console application: 

```
> averagei
0 55 222 41 11<EOF>
Average: 65.8
```

Once you are done, change your program to accept floating point numbers instead (`averagef()`). How many places do you need to change?


  - **Tip:** you can base this program on your sum numbers program.

## c) Multiplication table (nested loops)
 
Write a program `multab` to print a multiplication table for the integers from `1` to `20`. Make it more flexible, so that one can input the maximum factor up to `30` and create the table up to that factor. Make the table look nice and aligned if printed with a fixed-width font.

Example: 

```
> multab
Enter limit (max 30):5
    1    2    3    4    5
    2    4    6    8   10
    3    6    9   12   15
    4    8   12   16   20
    5   10   15   20   25
```


## d) Decimal Fractions 
 
Can you vary your program `multab` to print a table of decimal fractions (`fractab`) for `a` divided by `b`, where `a` and `b` take the range from `1` to `10`?

Example: 

```
> fractab
enter limit (max 10):6
        0        1        2        3        4        5        6
        1        1      0.5  0.33333     0.25      0.2  0.16667
        2        2        1  0.66667      0.5      0.4  0.33333
        3        3      1.5        1     0.75      0.6      0.5
        4        4        2   1.3333        1      0.8  0.66667
        5        5      2.5   1.6667     1.25        1  0.83333
        6        6        3        2      1.5      1.2        1
```

---
keywords:
- c++
title: 'Functions and Expressions'
---
