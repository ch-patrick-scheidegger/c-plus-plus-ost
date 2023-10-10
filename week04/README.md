## Reading C++ Code
This exercise combines various C++ code elements you should be able to at least understand and explain with your current knowledge.

Read the program and try to figure out what it does. The following topics occur in the example:
*  Includes (Week 1)
*  A class with a simple member function (Week 1)
*  Writing to streams (Week 1) with Iterators (Week 3/4)
*  Using simple algorithms with iterators (Week 3)
*  Namespaces (Not yet covered)
*  Lambdas (Week 4)

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

namespace Games {

struct FizzBuzz {
  auto run(unsigned n, std::ostream &out) -> void {
    std::ostream_iterator<std::string> outIter{out, "\n"};
    auto gen = [this] {
      value++;
      std::string result{};
      if (value % 3 == 0) {
        result += "Fizz";
      }
      if (value % 5 == 0) {
        result += "Buzz";
      }
      if (result.empty()) {
        result = std::to_string(value);
      }
      return result;
    };
    std::generate_n(outIter, n, gen);
  }

private:
  int value{};
};

} // namespace Games

auto main() -> int {
  Games::FizzBuzz fb{};
  fb.run(15, std::cout);
}
```

**Note:** This example is artificial, some parts of it are not solved in the shortest possible way.

---

## 1 _Testat-Exercise 1_: Calculator with Retro Style Output

**Hand in time is Sunday Oct 22 2023, 23:59 (PM)**

Hand in you solution via [ALF](https://alf.sifs0005.infs.ch/project/23/submission/new/) **CPl23 Testat 1 Pocketcalculator**. In case ALF does not work or is too slow, you can send an email to both Thomas and Felix.

Use the functions implemented in the previous two weeks to create a simple pocket calculator simulation. Allow the user to enter a calculation using two integers and an infix operator symbol. This input should stand on a single line and the result of the calculation should be displayed in a large way using your seven segment display simulation from last week. In this exercise the display width should be limited to a maximum number of eight digits (<=8) including a large minus sign for negative numbers. This limitation should be implemented in the pocket calculator, not the seven segment functionality itself. For the underlying calculation use your function **`calc()`**. Read the input line by line (`std::getline()`) and interpret each line as a calculation (operand operator operand). Expected signature: `void pocketcalculator(std::istream &, std::ostream&)`

```
6*7
    - 
| |  |
 -  -
  ||  
    - 
1*0
 - 
| |
   
| |
 - 
```

If the format is wrong or the calculation is invalid, display "Error". You can define additional "digits" in your seven-segment display for the letters "E", "r" and "o" to make the Error message fit your retro-style. Expected signature: `auto printLargeError(std::ostream &) -> void`

**Hint:** Use your knowledge about exceptions from the lecture to handle error cases properly!

**Hint:** If you have not done already, use the same trick as for Ero also for the minus sign to put in front of your number.

```
1/0
 -             
|              
 -  -  -  -  - 
|  |  |  | ||  
 -        -    
```

*  If the result of the calculation is wider than eight digits it is considered an overflow, which is an "Error" too. Implement the width check in your new function `pocketcalculator()`.

**Note:** You cannot determine the width of your console in a portable way.


### Automated Checking

Our platform for automated testat checking (ALF) will expect you to provide the following files:

* Calc.hpp
* Calc.cpp
* Sevensegment.hpp
* Sevensegment.cpp
* Pocketcalculator.hpp
* Pocketcalculator.cpp

Which provide functions with the following signatures:

```c++
//From Calc.hpp/.cpp
auto calc(int, int, char) -> int;
auto calc(std::istream &) -> int;

//From Sevensegment.hpp/.cpp
auto printLargeDigit(int i, std::ostream &out) -> void;
auto printLargeNumber(int i, std::ostream &out) -> void;
auto printLargeError(std::ostream &out) -> void;

//From Pocketcalculator.hpp/.cpp
auto pocketcalculator(std::istream &in, std::ostream &out) -> void;
```

The testat verification tool ([ALF](https://alf.sifs0005.infs.ch)) is still experimental. Sorry, for the upload you have to select the files individually, which is a bit tedious right now. You can upload your testat to get a first feedback. We have implemented some tests there which check your solution. Your chances to get positive feedback are very high if all unit tests pass. As we need to know who uploads what you need an account on https://gitlab.ost.ch for this. You should also be able to hand-in through ALF and select the team members who paritipacted in the submission.

---

## 2 Word List

Write a program **wlist** that reads all words (as defined by `std::string`'s input operator `>>`) from the standard input and produce a sorted list of all occurring words, where each word only is printed once. What data structure and algorithms are you using? Do not write your own loops nor use `std::(ranges::)for_each`.

*  In a second version: Ignore the case of letters, so that `Hello == hello`.

*  Question: How can you ignore non-letter characters in the input stream?

**Hints:**
*  Have a look at functions defined in `<cctype>` (character-type) and the available algorithms in `<algorithm>` (`std::lexicographical_compare`).
*  To implement the functionality with an `std::vector` you might need further algorithms: `sort` and `unique`

---

## 3 Function countingToLower

Implement a function **countingToLower** that makes the following test cases pass.

* What signature do you need to implement that function? Think about it, before you look at the exercise template.
* Is the resulting design and interface of the function `countingToLower` a good design? Why is it not good? If so, how could it be improved?
* The test cases are already provided for you in the exercise template. As we would like to have all tests in the repository pass, most tests are not registered in the corresponding suite. You need to uncomment them.

---

## 4 Function-Value Table

Create a function `printFunctionTable` that takes an `std::ostream`, a beginning and end value of type `double`, a number of steps, and a function on double as arguments. The function will produce a table of function values as follows by dividing the range given into `n` steps and prints the function results as follows:
`(start=1.0, end=3.0, steps=3, f(x) = [](double x){return x*x;})`

Expected Output:
```
x    1.0 2.0 3.0  
f(x) 1.0 4.0 9.0
```
You store the `n` used `x` values in a `std::vector<double>` first, by using the algorithm `std::(ranges::)generate_n`.

Make sure that the printed values always have one decimal digit after the comma/dot.


## 5 Experiment: Look into Object files (Optional)

To understand details of C++ linking and libraries, we will look into the structure of object and library files. On Linux (Unix, MacOS, MSYS2 on Windows) exists the program **`nm`** that prints the content of binary object files, libraries or executables on standard output. Use that command in a terminal and check out its output if you give one of your own compiled files as input. You will find those in the _build/_ folder in your workspace.

Even if you do not understand all details of its output try to find the encoding of your (overloaded) functions within a object file or library of your **calc** and **sevensegment** object files and libraries.

*  use the **man** command to get more information about **nm**
  *  Try to figure out what the letter in the second column of nm's output means.
*  what output do you get on your first hello world executables
*  what happens, if you apply the program **`strip`** on that executable and then call `nm` with the such change executable program?
*  Does it make a difference to `nm` if you put your functions in a namespace? What if you put your function in an anonymous namespace?
*  Use the program  `c++filt` in a pipeline with `nm` to get the encoded C++ names back into a readable format.
 nm hello.o | c++filt

In most cases you do not need to care about these details, because the linker will handle that for you. However, the experiment can improve your understanding of the compilation model and the (limited) meta information that object files carry. Unfortunately, there is no easy access from a program to the meta information the linker needs to know about. But the experiment will help you understand linker error messages better in the future.


---

## Extra exercises

### Experiment: Timing Parameter Passing Variation

The code frame in the exercise template features a function that creates a large vector and passes this large vector 100 times by value, effectively copying it to a function. To avoid having an optimizer optimize it away the function itself returns a random element from the given vector.

Your tasks:

-  Measure the difference of the above test code for a Debug and a Release build. You should be able to switch in CMake (Bottom bar in VSCode).
-  Modify/Extend the code to allow the following variation:
   - Pass the `TestData` by `const &` (new function `passByCref`, new looping function `refInAndOut`)
   - Create the `TestData` within the loop (100 times) new function `copyFromLoop`
   - Do not return anything from `passByValue/Cref`
-  Can you explain the differences? Do you get similar results with a much smaller / much larger vector and correspondingly more/fewer loops (instead of 100).
-  What do you judge to use for your own code in the future?
