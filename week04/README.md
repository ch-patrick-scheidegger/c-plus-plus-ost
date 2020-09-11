## Reading C++ Code
This exercise combines various C++ code elements you should be able to at least understand and explain with your current knowledge.

Read the program and try to figure out what it does. The following topics occur in the example:
*  Includes (Week 1)
*  A class with a simple member function (Week 1)
*  Writing to streams (Week 1) with Iterators (Week 3/4)
*  Using simple algorithms with iterators (Week 3)
*  Namespaces (Not yet covered)
*  Lambdas (Week 4)

```
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

namespace Games {

struct FizzBuzz {
  void run(unsigned n, std::ostream & out) {
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

}

int main(int argc, char **argv) {
  Games::FizzBuzz fb{};
  fb.run(15, std::cout);
}
```

**Note:** This example is artificial, some parts of it are not solved in the shortest possible way.

## 1 _Testat-Exercise 1_: Calculator with Retro Style Output
**Hand in time is Monday Oct 21 2019, 12:00 (noon) (CEST)**

**Hand in all your source files attached to a single email to thomas.corbat@hsr.ch, peter.sommerlad@hsr.ch . NO ZIP, NO object files, NO eclipse project.**
*  Subject: **[C++-testat-1] hsrname1 hsrname2 hsrname3**
  *  replace hsrname1, hsrname2 and hsrname3 with the HSR ids of the students in the team

  *  Example
    *  Subject: [C++-testat-1] m1huber fmorgner
    *  To: thomas.corbat@hsr.ch, peter.sommerlad@hsr.ch

*  Team size **2-3 students**! (please team up accordingly)
  *  (almost) identical hand ins from different teams will be considered cheating!
*  Your list of files should be the following: **Test.cpp, main.cpp, calc.h, calc.cpp, sevensegment.h, sevensegment.cpp, pocketcalculator.h, pocketcalculator.cpp**
*  the files calc.h calc.cpp sevensegment.h sevensegment.cpp should be those from the last weeks' exercises or newer versions of them.
*  Test.cpp combines all test functions you created for calc(), seven segment functions, and the new tests for the integrated pocketcalculator.


Use the functions implemented in the previous weeks to create a simple pocket calculator simulation. Allow the user to enter a calculation using two integers and an infix operator symbol. This input should stand on a single line and the result of the calculation should be displayed in a large way using your seven segment display simulation from last week. In this exercise the display width should be limited to a maximum number of eight digits (<=8) including a large minus sign for negative numbers. This limitation should be implemented in the pocket calculator, not the seven segment functionality itself. For the underlying calculation use your function **`calc()`**. Read the input line by line (`std::getline()`) and interpret each line as a calculation (operand operator operand). Expected signature: `void pocketcalculator(std::istream &, std::ostream&)`

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

If the format is wrong or the calculation is invalid, display "Error". You can define additional "digits" in your seven-segment display for the letters "E", "r" and "o" to make the Error message fit your retro-style. Expected signature: `void printLargeError(std::ostream &)`

**Hint:** Use your knowledge about exceptions from the lecture to handle error cases properly!

**Hint:** If you have not done already, use the same trick as for Ero also for the large space and minus sign to put in front of your number.

```
1/0
 -             
|              
 -  -  -  -  - 
|  |  |  | ||  
 -        -    
```

*  If the result of the calculation is wider than eight digits it is considered an overflow, which is an "Error" too. Implement the width check in your new function `pocketcalculator()` **Note:** You cannot determine the width of your console in a portable way.

*  Create tests for all your infrastructure (you can combine the tests you created for the calc library and your seven segment digit output). If you want to separate them, create CUTE test suites in your project.

*  Create a separate executable project that uses your library and only consists of a very simple `main()` function passing `std::cin` and `std::cout` to your `pocketcalculator()` function.

### Automated Checking

Our platform for automated testat checking (ALF) will expect you to provide the following files:

```
calc.h
calc.cpp
sevensegment.h
sevensegment.cpp
pocketcalculator.h
pocketcalculator.cpp
```

Which provide functions with the following signatures:

```cpp
//From calc.h/.cpp
int calc(int, int, char);
int calc(std::istream &);

//From sevensegment.h/.cpp
void printLargeDigit(int i, std::ostream &out);
void printLargeNumber(int i, std::ostream &out);
void printLargeError(std::ostream &out);

//From pocketcalculator.h/.cpp
void pocketcalculator(std::istream &in, std::ostream &out);
```

The testat verification tool is still experimental. You can upload your testat to https://uploader.alf.infs.ch/ in order to get a first feedback. Your chances to get positive feedback are very high if all unit tests pass. As we need to know who uploads what you need an account on https://gitlab.dev.ifs.hsr.ch for this. Please note that external login (oauth) is not activated, but you can create an account with your HSR mail address.


## 2 Word List
Write a program **wlist** that reads all words (as defined by std::string's input operator >>) from the standard input and produce a sorted list of all occurring words, where each word only is printed once. What data structure and algorithms are you using? Do not write your own loops nor use `std::for_each`.

*  Can you ignore the case of letters, so that `Hello == hello` ?

*  Can you ignore non-letter characters from input?

**Hints:**
*  Have a look at functions defined in `<cctype>` (character-type) and the available algorithms in `<algorithm>` (`std::lexicographical_compare`).
*  To implement the functionality with an `std::vector` you might need further algorithms: `sort` and `unique`
 
## 3 Function countingToLower
Implement a function **countingToLower** that makes the following test cases pass.

*  What signature do you need to implement that function?
  *  Note, it can be auto-generated from the test cases via CTRL-1 quick fix, but first try to make your own guess.
*  Is the resulting design and interface of the function countingToLower a good design? Why is it not good? If so, how could it be improved?

```
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void lowerFirstCharacter() {
	std::string str("Hello!");
	ASSERT_EQUAL(1, countingToLower(str));
	ASSERT_EQUAL("hello!", str);
}

void lowerSeveralCharacters() {
	std::string str("Hello World, its ME!");
	ASSERT_EQUAL(4, countingToLower(str));
	ASSERT_EQUAL("hello world, its me!", str);
}

void lowerNone() {
	std::string str("no uppercase characters here");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("no uppercase characters here", str);
}

void lowerAll() {
	std::string str("LOL");
	ASSERT_EQUAL(3, countingToLower(str));
	ASSERT_EQUAL("lol", str);
}

void lowerEmpty() {
	std::string str("");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("", str);
}

void umlautsAreNotChanged() {
	std::string str("ÄÖÜ");
	ASSERT_EQUAL(0, countingToLower(str));
	ASSERT_EQUAL("ÄÖÜ", str);
}
void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(lowerFirstCharacter));
	s.push_back(CUTE(lowerSeveralCharacters));
	s.push_back(CUTE(lowerNone));
	s.push_back(CUTE(lowerAll));
	s.push_back(CUTE(lowerEmpty));
	s.push_back(CUTE(umlautsAreNotChanged));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
}
```



## 4 Function-Value Table
Create a library with a function **printFunctionTable** that takes an ostream, a beginning and end value of type double, a number of steps, and a function on double as arguments. The function will produce a table of function values as follows by dividing the range given into `n` steps and prints the function results as follows:
(start=1.0, end=3.0, steps=3, f(x) = [](double x){return x*x;})

Expected Output:
```
x    1.0 2.0 3.0  
f(x) 1.0 4.0 9.0
```
You store the `n` used `x` values in a `std::vector<double>` first, by using the algorithm `std::generate_n`.

Demonstrate your function beyond your unit tests by a `main()` function that displays the functions `std::sin(x)`, `std::cos(x)`, `std::tan(x)` for x from `0` to `pi` in `19` steps (10 degrees each).


## 5 Experiment: Look into Object files (Optional)

To understand details of C++ linking and libraries, we will look into the structure of object and library files. On Linux (Unix, MacOS, MinGW on Windows) exists the program **`nm`** that prints the content of binary object files, libraries or executables on standard output. Use that command in a terminal and check out its output if you give one of your own compiled files as input. You will find those in the _Debug/_ folder in your project directories.

Even if you do not understand all details of its output try to find the encoding of your (overloaded) functions within a object file or library of your **calc** and **sevensegment** object files and libraries.

*  use the **man** command to get more information about **nm**
  *  Try to figure out what the letter in the second column of nm's output means.
*  what output do you get on your first hello world executables
*  what happens, if you apply the program **`strip`** on that executable and then call `nm` with the such change executable program?
*  Does it make a difference to `nm` if you put your functions in a namespace? What if you put your function in an anonymous namespace?
*  Use the program  `c++filt` in a pipeline with `nm` to get the encoded C++ names back into a readable format.
 nm hello.o | c++filt

In most cases you do not need to care about these details, because the linker will handle that for you. However, the experiment can improve your understanding of the compilation model and the (limited) meta information that object files carry. Unfortunately, there is no easy access from a program to the meta information the linker needs to know about. But the experiment will help you understand linker error messages better in the future.



<hr/>

## Extra exercises

### Experiment: Timing Parameter Passing Variation 
The following code frame uses a function that creates a large vector and pass this large vector 100 times by value, effectively copying it to a function. To avoid having an optimizer optimize it away the function itself returns a random element from the given vector.

```
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <random>


constexpr size_t testsize{1000000};

using testdata=std::vector<std::string>;
size_t random_index(){
    static std::random_device rd{};  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen{rd()}; //Standard mersenne_twister_engine seeded with rd()
    static std::uniform_int_distribution<size_t> dis{0, testsize-1};
    return dis(gen);
}

std::string pass_by_value(testdata v){
	size_t index = random_index();
	return v[index];
}
void copying_source_outside(){
	testdata v(testsize," ");
	for (int i = 0; i < 100; i++)
	{
		auto res = pass_by_value(v);
	}
}

std::chrono::microseconds time_func(void  (f)()){
	using namespace std::chrono;
	high_resolution_clock clock { };
	auto start=clock.now();
		f();
	auto end = clock.now();
	return duration_cast<microseconds>(end - start);
}
int main(){
	auto elapsed = time_func(copying_source_outside).count();
	std::cout << "source_outside :" << elapsed << " us\n";
}
```

*  Measure the difference of the above test code for a Debug and a Release build in Eclipse.
*  Modify/Extend the code to allow the following variation:
  *  pass the testdata by const & (new function pass_by_cref, new looping function ref_source_outside)
  *  create the testdata within the loop (100 times) new function copying_source_inline
  *  do not return anything from pass_by_xxxx
*  Can you explain the differences? Do you get similar results with a much smaller / much larger vector and correspondingly more/fewer loops (instead of 100).
*  What do you judge to use for your own code in the future?
