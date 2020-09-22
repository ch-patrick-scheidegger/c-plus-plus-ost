# 1. Questions about the Lecture

  - Please figure out, in which standard header file the following elements of `namespace std` are declared. Also point out, if it is a variable, function or type. Please note, in a concrete compiler implementation the exact place might be in another header file than the official standard one. You should provide the latter. Consult provided online references, if in doubt and to check your answers. But first try Cevelop's means (experiment with CTRL-click and the include browser!). If there is a difference in the position where the element is defined according to Cevelop and the standard documentation give both headers and try to explain it!
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
int main() {
  int i{};
  std::cin >> i;
  //...
}
```

---

**Important:** For all exercises working with standard input (`std::cin`) you might want to terminate the input stream. You should be able to do this on Windows with `ctrl-z` and on Unix-like systems with `ctrl-d`.

---


# 2. Simple calculator (**future testat hand in!**)

**Note:** For the testat you can and should work in groups of up to three students.

In this exercise you will...

  - implement a function for performing different operations on function parameters and return the result.
  - read formatted input from an `std::istream`
  - split a project containing an implementation and tests into tree projects: `library` (with implementation), `tests` and `executable`. This is a repetition of the modularization you have already performed on the `SayHello` project last week.



## a) Implement a `calc` function

Create a function with the signature `int calc(int, int, char)` that takes two numbers an a character denoting an operator symbol (`'+'`, `'-'`, `'*'`, `'/'` and `'%'`). The function `calc` should interpret the operator character and compute its result by combining the two integers accordingly. To give you a headstart you can use the code below in a CUTE Project as `Test.cpp`. Add additional test cases for the corner cases of the function. Consider and test valid and invalid input, e.g. unknown operators and division by zero. What options for error handling are feasible? Discuss them with your supervisor and your peers.

To start, just use a single CUTE Test Project and develop your code there. In the last part of this exercise you will split the code into different projects.

```cpp
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

int calc(int lhs, int rhs, char op) {
  //TODO Implement functionality
  return 0;
}

void test_one_plus_one() {
  auto result = calc(1, 1, '+');
  ASSERT_EQUAL(2, result);
}

//TODO Add more tests here


bool runAllTests(int argc, char const *argv[]) {
  cute::suite s { };
  //TODO Register tests
  s.push_back(CUTE(test_one_plus_one));
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  auto runner { cute::makeRunner(lis, argc, argv) };
  bool success = runner(s, "AllTests");
  return success;
}

int main(int argc, char const *argv[]) {
  return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

Hint for the implementation: Consider using a switch statement in the `calc` function.

## b) Extension: Simple calculator with stream input (future hand in)

Extend your simple calculator from above and create an additional function `int calc(std::istream& in)` that will read a number, an operator character and another number from the `istream` `in` and compute the result of the operation. E.g. `1 + 1` results in `2`. Also provide unit tests for this new calculator. 

When tests for a function taking an `std::istream &` as argument, you have to create an `std::istringstream` that contains the given input.

```cpp
void testCalcWithStream() {
  std::istringstream input{"95/5"};
  auto result = calc(input);
  //...
}
```

## c) Modularization: Separate Projects

You have implemented the complete functionality of the `calc` function in the unit test project. In order to use them in an executable it would be desirable to have them in a separate library. This is best realized stepwise.

  - Separation into new compilation unit (`.cpp` file)
    - Move the `calc` functions to a new source file (`calculator.cpp`) in the test project
    - To be able to use the `calc` functions from the tests in the `Test.cpp` file a header file with the corresponding declarations is required. Create a header file (`calculator.h`) which contains an include guard and the declarations for both functions.
    - Add an include directive for including the `calculator.h` header file to both source files `Test.cpp` and `calculator.cpp`.


Now your test project should compile without errors and run as before. If not figure out why and fix remaining errors. 

  - Separation into distinct projects
    - Create a new Static Library Project
    - Move the files `calculator.h` and `calculator.cpp` to this new project
    - Now we need to tell Cevelop that there is a dependency from the test project to the new library project
      - Open the references of the test project: Right-click on the test project `-> Properties -> C/C++ General -> Paths and Symbols -> References (Tab)`
      - Tick the library project and press apply. This should automatically add the library project to the includes (Includes tab), the library of the library project (`Library` tab) and the library path of the library project (`Library Paths` tab). If those are missing add them manually - ask for assistance if it does not work.


Now your test project should compile without errors and run as before. If not figure out why and fix remaining error. 

  - Executable project 

Now create an executable project with a `main.cpp` source file that contains the following main function. You have to set up the dependencies from the executable project to the library project as well (See steps above). Then you can use your calculator from the console.

```cpp
int main() {
  while (std::cin) {
    std::cout << '=' << calc(std::cin) << '\n';
  }
}
```

**Note:** The function `calc()` with all of its test will be part of the first hand in later ("Testat"). Show your solution including your CUTE unit tests to your exercise supervisor, you will get feedback!


---


# 3. Counting Input Elements
In this exercise you will...

  - implement various character counting algorithms.
  - use the input operator (`>>`) to read different types from `std::istream`.
  - figure out how when the input operator (`>>`) skips white-space characters and how to avoid that skipping.

**Hints:**

  - Please consult your C++ reference on `iostreams` to figure out which member function to use, if the input operator `>>` doesn’t help with solving the problem. 
  - Like in the previous exercise start with a CUTE Project and implement the functions and tests directly in the `Test.cpp` file. Afterwards, when you are happy with your code you can separate the tests and the implementation as described above. 
  - You should use an `std::istringstream` to provide your input from in test cases.
  - Do not forget to write unit tests for the following cases:
    - How does your functional core behave with empty input? 
    - Do you always get the result you are expecting?
  - Try not to store too much of the input
  - All the counting programs should look quite similar in structure
  - If you experience problems because your program does not terminate properly try to shut down your program using the red box in the Console window it is running within Cevelop
  - It can cause to hang your Cevelop IDE on some of the platforms (Mac). When that happens, you need to kill your own program from a terminal window or task manager/system monitor/activity monitor. This should make Cevelop usable again. If all fails, you might need to restart Cevelop as well



## a) charc: Count non-whitespace char
 
Write a function `charc()` to count non-whitespace char values by reading from an input stream (`std::istream)`). The result should be the number of characters found in the stream.

```cpp
unsigned charc(std::istream & input) {
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


**Question:** Can you find other means (than the member function of `std::istream`) to not skip the white space?

## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from standard input.

**Hint:** There are several means to achieve that, for example, count the characters matching the newline character `'\n'`, or, use the `getline()` function and count how often you can call it until you reach the end of the input.

## e) Modularization
 
After you have implemented all functions you can split up the structure as follows:

  - Library project that contains all the implementations of the functions. It contains two files `charcount.cpp` and `charcount.h`
  - A test project for testing the library. It contains the `Test.cpp` file with all CUTE tests. You can also split the test functions into CUTE suites for each function, if you like.
  - An executable project for each feature: `charc()`, `allcharc()`, `wc()` and `lc()`. In each executable project there only exists a `main.cpp` with a simple main that calls the corresponding library function with `std::cin` as argument and prints the result to `std::cout`.


**Note:** Do not write any fancy "UI", so that you can use your programs also as filters within a shell-pipeline.

Compare the result of your function with the size of the file you use as input on the console (e.g., `$ allcharc < file.txt`). You executables should be located in the `Debug` directory of the executable project.


---


# 4. Experiments (see also lecture code)
 
In this exercise you will...

  - experience an example of undefined behavior, i.e. the evaluation order function arguments.
  - figure out the precedence of operators.
  - experiment with invalid input in `std::istream`


## a) Experiment: output with conditional operator
 
What happens if the following piece of code gets compiled and executed as part of a main function? 

```cpp
#include <iostream>

int main() {
    bool cond{};
    std::cout << cond ? "Hello" : "Peter";
}
```

Can you explain your observation? Can you fix the code to get what one might expect.

**Hint:** [CPPReference](http://en.cppreference.com/w/cpp/language/operator_precedence) might help.

## b) Questions/Experiments on input behavior

  - What happens if a user provides an invalid number to `std::cin >> anAnswer;`? Can the program continue to read further numbers?
  - How can you read a `std::string name` with the code `std::cin >> name;` if the name provided consists of several words? How can you read the rest of the input into the string variable?
  - Look at declaration of `std::getline()` function and explain its parameter passing. Why is the `std::string` parameter passed as reference?


---

# 5. Optional exercises (also for self-study)

## a) Sum numbers
 
Write a program `sumi()` to sum up a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are given. Print the resulting sum on standard output.

Example: Input `0 55 222 41 11` should result in `329`

Once you are done, change your program to accept floating point numbers instead ('sumf'). How many places do you need to change?


## b) Average numbers
 
Write a program `averagei()` to calculate the average of a sequence of integer numbers given in standard input. Assume only numbers separated by whitespace are provided. Print the resulting average with the number of elements on standard output.

Example: 

```
> averagei
0 55 222 41 11<EOF>
Average: 65.8
Count: 5
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
enter limit (max 30):6
        0        1        2        3        4        5        6
        1        1      0.5  0.33333     0.25      0.2  0.16667
        2        2        1  0.66667      0.5      0.4  0.33333
        3        3      1.5        1     0.75      0.6      0.5
        4        4        2   1.3333        1      0.8  0.66667
        5        5      2.5   1.6667     1.25        1  0.83333
        6        6        3        2      1.5      1.2        1
```

## e) Bartender cheat sheet (loops)
 
The VSHSR bartender who sells lots of drinks on the semester party might have a few drinks herself. Multiplication of drink prices can thus become a challenge. 

Create a multiplication sheet for the multiples up to `10` times for the following drinks: *small* Beer 4.65, a *Moaß* Beer 9.15, Schnapps 3.85, Soda 2.95. This sheet will help the bartender with her task of asking for the money when one buys a round.


  - Can you make the application configurable, so that there is one place where you can specify a drink and its unit price an generate tables for arbitrary drinks or price changes easily?

---
keywords:
- c++
title: 'Functions and Expressions'
---
