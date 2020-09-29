In this week, we will start with an exercise that will be combined into a hand-in next week (Testatabgabe).

However, to get into the mood of programming you might start with the simpler counting exercises first. But those shouldn't take too long to solve. If you find you are too slow, there is only one remedy: exercise exercise exercise... OTOH, if you are stuck during the exercise lesson, do not just wait until your supervisor shows up at your place, but actively seek support, either by him or by your fellow students.

If your workspace accumulates too many projects and you loose the overview on what you are working on, close the old projects and hide the closed projects from the workspace using the workspace preferences or define working sets in the project view (little triangle button).

# 0. Self-study 

## a) Self-Study on CPP Reference
* Take a look at the features of std::vector and std::string:
  * http://en.cppreference.com/w/cpp/container/vector
  * http://en.cppreference.com/w/cpp/string

* Also consult some of the algorithms we encountered:
  * http://en.cppreference.com/w/cpp/algorithm

## b) Videos

* [Iterators and Algorithms](https://skripte.hsr.ch/Informatik/Fachbereich/C++/CPl/Videos/3.%20iterators%20and%20algorithms.mp4) (On Skripte server, only accessible from HSR)
* [ 105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=bXkWuUe9V2I) - Jonathan Boccara ACCU 2018 on YouTube

# 1. Simulated 7-Segment Display for Numbers

**This exercise will be part of the "Testat" hand in**.

Create a function `printLargeNumber(int i, std::ostream &out)` that allows you to output a large number on a simulated 7-segment digits display. We will use that function later on for the Testat. For example, the number 1234567890 should be output as
```
    -  -     -  -  -  -  -  - 
  |  |  || ||  |    || || || |
    -  -  -  -  -     -  -    
  ||    |  |  || |  || |  || |
    -  -     -  -     -  -  - 
```
*Note:* Stick with the representation above in order to check your solution against ALF, a tool for preliminary checks of the testat solution.

To achieve that goal, first start with a function `printLargeDigit(int i, std::ostream &out)` to print such a single large digit given by a number. `printLargeDigit(int i, std::ostream &out)` will produce a simulated 7-segment-digit for the numbers 0,1,2,...,9 given as parameter `i`. 

Provide unit tests for the output of that number. An example output for the digit 8 looks as follows:
```
 - 
| |
 - 
| |
 - 
```

For the "production code" of `printLargeDigit` and `printLargeNumber`, create a separate library project with a header declaring the function(s) and an implementation file for their implementation. Note that you should minimize dependencies to other files, even the standard library, in header files. 

Tips: 
*  use a `std::array<std::array<std::string, 5>, 10>` and initialize it with the 5 lines representing each digit, e.g., use `" - ", "| |"` for the first two rows of digit zero. The "outer" vector contains 10 digits and the inner vector the representation of each digit (the five lines).
*  Can you minimize the use of hand-written loops? Note: `printLargeDigit` can be solved without custom loops.
*  Show your solution as early as possible to your supervisor for feedback. 
*  Work in small teams (up to 3) to speed up your programming time and increase your result quality.
*  Getting this working together with appropriate unit tests is important, since you need the solution for your testat exercise next week.
*  You won't be able to use `printLargeDigit` to implement `printLargeNumber`.

For unit testing your functions you can rely on string splicing to have a nice representation of the expected result. String splicing combines (splices) adjacent string literals at compile-time to single string literal. Example test case:

```
void testPrintLargeDigitZero() {
  std::ostringstream output{};
  printLargeDigit(0, output);
  ASSERT_EQUAL(" - \n"
               "| |\n"
               "   \n"
               "| |\n"
               " - \n", output.str());
}
```

**Note for 2019:** State clearly that negative Numbers should be printed as well! Hand-in must include both: `printLargeDigit` and `printLargeNumber`.

# 2. Counting again - without loops
This week we repeat some of the exercises of last week. However, now you need to solve the task without writing a loop of your own, but by using iterators and algorithms of the standard library. One function you might need to know about is `std::distance()` that takes two iterators forming a range and returns the number of elements in that range. Using distance is convenient for counting all elements in a range.

If you are unsure about the correct solution, start out with encapsulating it in a function and write unit tests first using `std::stringstream` objects as input and output substitutes. Create all solutions by using algorithms instead of loops. If you can not achieve that, please ask your supervisor for tips.

**Hints:**

  - Like in the previous exercises start with a CUTE Project and implement the functions and tests directly in the `Test.cpp` file. Afterwards, when you are happy with your code you can separate the tests and the implementation as described above. 


## a) charc: Count non-whitespace char
 
Write a function `charc()` to count non-whitespace char values by reading from an input stream (`std::istream)`). The result should be the number of characters found in the stream.

```cpp
unsigned charc(std::istream & input) {
  //Your implementation of charc
}
```

## b) allcharc: Count all characters
 
Create a function `allcharc()` with the same signature as `charc()`. The `allcharc()` function must not skip white-space characters when counting.

**Hints:**

  -  You need to use the stream iterator that does not skip whitespace characters to achieve that.


## c) wc: Count words
 
Write a function `wc()`, calling it to count words separated by white space character by reading from a given `std::istream`. The result should be the number of words found in the stream. Use an iterator and `std::distance()` to calculate the result.

A word should be defined by what the input operator (`>>`) decides to be read as a `std::string`.

## d) lc: Count lines
 
Write a function `lc()` to count the lines by reading from an istream.

After checking its functionality using some unit tests, use that function in a program **lcount** that counts the number of lines available on standard input. The result should be printed on standard output. Compare your output with the result of the _wc -l_ command on a large text file.

<hr/>

# Extra exercises for self-study (Optional)

## 3. Scaleable 7-Segment Digit Number Display
Vary your functions from above so that they take an additional parameter: a scaling factor `n`. The digit(s) are scaled, by repeating the middle character of each line `n` times and by repeating the 2nd and 4th row of the unscaled digit `n` times. The number 8 scaled by factor 2 looks like this:
```
 -- 
|  |
|  |
 -- 
|  |
|  |
 -- 
```
To avoid duplicating code and because we do not have classes yet, you can define the shared data structure with the solution above as a global constant (which is not as poisonous as a global variable).

Note: this exercise allows hand-written loops for the scaling. But you can try to find a solution with as few loops as possible. Maybe, you can experiment to create a solution that relies on algorithms only.

## 4.  Sum numbers

Write a function **sumi(std::istream&)** to sum up a sequence of integer numbers given on an input stream. Assume only numbers separated by whitespace are given. Return the resulting sum. Do not use a loop. How much would need to change to sum floating point numbers instead? Do so but in a separate function called **sumd(std::istream&)**

## 5.  Multiplication table

Write a program **multab** to print a multiplication table for the integers from 1 to 20. Start by filling a `std::vector<int>` with the numbers 1 to 20. You shouldn't use a loop to create the table, therefore you might need to nest algorithm calls in a lambda expression or function call to get the nested iteration. The output can be generated onto an `std::ostream_iterator` with an algorithm that 'transforms' its input.

Note: **use a lambda with capture by reference:**
```
[&](auto x){...}
```

## 6. Decimal Fractions
Can you vary your program _multab_ to print a table of decimal fractions (**fractab**) for a divided by b, where a and b take the range from 1 to 10? Also without any self-made loops.
