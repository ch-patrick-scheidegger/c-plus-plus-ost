# Testat-Exercise 2: KWIC with word class

**Hand-in time is Monday 16. Nov 2019, 11:30 (AM) (CET)**

Hand in your solution via MS Teams using the assignment Testat 2.
Hand in the following files

* Test.cpp
* main.cpp
* word.h
* word.cpp
* kwic.h
* kwic.cpp

`Test.cpp` combines all test functions you created for your `Word` class as well as for your `kwic` solution.
`main.cpp` contains the `main()` function for your `kwic` program.

## KWIC - Keyword in Context (Testat)

From Parnas [[Parnas72](http://dl.acm.org/citation.cfm?id=361623&coll=ACM&dl=ACM)] we have a concise definition of the Keyword in Context problem:


> The KWIC index system accepts an ordered set of lines,  each line is an ordered set of words, and each word is an ordered set of characters. 
Any line may be "circularly shifted" by repeatedly removing the first word and appending it at the end of the line. 
The KWIC index system outputs a listing of all circular shifts of all lines in alphabetical order. 

**Note:** In the description *ordered set* does not mean a sorted set like the `std::set` but rather a *sequence thereof*. If you lookup the definition in [Wikipedia](https://en.wikipedia.org/wiki/Key_Word_in_Context), you are expected to implement the functionality depicted in the *KWAC* example.

Write a function `kwic` that reads lines from standard input and creates the variations of the line where each word is in front once. Output the stored lines in sorted order, so that you can see, how the words are used in context.

Example input:

```
this is a test
this is another test
```

result:

```
a test this is
another test this is
is a test this
is another test this
test this is a
test this is another
this is a test
this is another test
```

Clarifying example input:

```
a b c d
a a b
b b c
```

result:

```
a a b
a b a
a b c d
b a a
b b c
b c b
b c d a
c b b
c d a b
d a b c
```
 

Tips:

* Use algorithms `rotate` or `rotate_copy` to generate the word lists for each line.
* You must use your `Word` class from week 5 to be able to ignore punctuation and case of the letters.
* Use the appropriate data structures to achieve the result without unnecessary code or loops.
* In addition to the test of your `Word` class you can also separate your logic into independently testable functions, provide the tests and your `main()` function.
* Create an alias for lines (`std::vector<text::Word>`) 

### Automated Checking

Our platform for automated testat checking will expect you to provide the following functionality:

```cpp
namespace text {

void kwic(std::istream & in, std::ostream & out);

}
```

Use [ALF](https://alf-uploader.sifs0005.infs.ch) to automatically check your `kwic` function and `Word` class (functionality, not style).

* You need an account on gitlab.dev.ifs.hsr.ch for this
* Testat 2, Teil 1 (`Word`) requires files `word.h` and `word.cpp`
* Testat 2, Teil 2 (`kwic`) requires files `kwic.h` and `kwic.cpp`
* Our tests expect the `Word` class and the `kwic` function to be in the namespace `text`
 

# Algorithms

## Algorithms Trivia

An introduction into this exercise is given in this weeks [video](https://skripte.hsr.ch/Informatik/Fachbereich/C++/CPl/Videos/8.%20Algorithms.mp4).

For using the existing STL algorithms effectively you have to familiarize yourself with available functionality. We have prepared a CUTE test project (`algorithm_trivia`) with a large set of test cases which require you to insert the correct STL algorithm in order to get the test green. It contains several test suites, each containing some test cases. Usually, those cases fail with the current implementation. We have replaced the original calls with dummy functions (`xxx`, `xxxx`, `xxxxx`, `xxxxxx`) that satisfy the interface. You don't have to worry about these helper functions. Your task is to fix the test cases by calling the correct STL algorithm (instead of the helper function).

Since there are quite a few algorithms you don't have to solve all algorithms at one. We suggest to solve 2-3 test suites each week. Each suite contains a hint header that lists the algorithms that have to be used in the corresponding suite file. Each algorithm is required once. Read the description of the algorithms first and then try to insert the correct calls. Some algorthims require a predicate. Most of the time we have used an `is_prime` function that just checks whether the parameter is prime.

Have Fun!


## Checking for Palindromes

 A palindrome is a word or sentence that can be read from its beginning and its end and results in the same word (in our example ignore whitespace). For example, the name "Otto" is a palindrome. Write a predicate `is_palindrome(std::string)` taking a string and returning if the string is a palindrome (ignoring letter case).

Use that function to find all palindromes in the dictionary file in the exercise templates.

# Generating Anagrams (Optional)

Write a program that reads a word from standard input and creates all possible anagrams (permutations of the letters in the word).

Use a data structure to collect the anagrams that keeps them in sorted order and eliminates duplicates.

On Linux/Mac/Unix you can read in the file /usr/share/dict/words into a data structure and filter your anagrams according to the valid words. Try this with short words first, otherwise generating the permutations might take a long time (factorial(size())).

How many anagrams forming a word according to your system's dictionary do you find for the word "listen" ?

**Extension:** Can you extend your program in a way that it also will check for valid anagrams consisting of multiple words, i.e., `"Vacation time" = "I am not active"` (might be a bit harder and slower). 
