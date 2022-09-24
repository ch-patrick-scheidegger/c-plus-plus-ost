# Solutions Week 02

Solutions for week 2 exercises, except for `calc()`

The functions calc with their tests are part of the "Testat".

*Note*: These solutions are bad C++, because they use their own loops. 
See week 3's solutions on how to solve these without own loop structures.

## 1. Questions about the Lecture

### Standard Library Symbols

 Provide the header where defined:

|name 	                 |headerfile     |variable | function |	type |description|
|------------------------|---------------|---------|----------|------|-|
|`std::cin`              |`<iostream>` 	 |    x    |          |      |Represent standard input stream|
|`std::endl` 	         |`<ostream>` 	 |	       |x 		  |      |Inserts a newline character into the output sequence os and flushes it as if by calling.|
|`std::tolower` 	     |`<cctype>` 	 |	       |x 		  |      |Converts given character to lowercase (A -> a).|
|`std::string` 	         |`<string>` 	 |		   |          |x 	 |Stores and manipulates sequences of char-like objects.|
|`std::distance` 	     |`<iterator>` 	 |	       |x 		  |      |Returns the number of hops from first to last.|
|`std::istream_iterator` |`<iterator>` 	 |		   |          |x 	 |Read successive objects of type T from the basic_istream.|
|`std::size_t`	         |`<cstddef>` 	 |		   |          |x     |Unsigned integer type of the result of the sizeof operator.|
|`std::vector` 	         |`<vector>` 	 |		   |          |x     |Sequence container that encapsulates dynamic size arrays. |

### Literals

|literal   |type                |
|----------|--------------------|
|`45`      |`int`               |
|`0XDULL`  |`unsigned long long`|
|`5.75`    |`double`            |
|`.2f`     |`float`             |
|`"string"`|`char const[7]`     |
|`' '`     |`char`              |

### Stream States

|input       |`failbit` |`eofbit` |`badbit` |
|------------|----------|---------|---------|
|`10`          |          |(x)      |         |
|`a`           |x         |         |         |
|`<no input>`|x         |x        |         |

**Note:**: For the input `10` it depends on the exact input whether the `eofbit` is set or not. If you enter 10<enter> on the console, i.e. you use the enter key to send the input, the `eofbit` will not be set. If you write a unit test with an `std::istringstream` containing only `10`, the `eofbit` will be set.

## 3b allcharc: Count all characters

There exists a modifier: `std::noskipws`, see [CPPReference](https://en.cppreference.com/w/cpp/io/manip/skipws).

## 4a unspecified sequence

The result of the program can be either that the left argument determined by `inputName()` is called before or after the right argument, also determined by `inputName()`.

## 4b output with conditional operator

The output operator (`<<`) binds stronger than the conditional operator (`?:`). Thus, the output will be the value of `cond` as integer, which is `0` converted from `false`. If you want to print `false` as a word for the output of a boolean expression you need the modifier `std::boolalpha`. The result of the expression is `"Hello"`, but that result is discarded.

## 4c Questions on input behavior

- If an invalid input is provided for formatted input the stream is put into `fail` state. It is not possible to read from a stream in this state. `clear()` resets the `failbit` and you can continue reading afterwards.

- You need multiple subsequent reads to read multiple words to `std::string`. There is an alternative to use an `std::istreambuf_iterator` to initialize the `std::string`, however, we have not looked at iterators yet.

- `std::getline()` returns the `std::istream` it reads from, this allows using it directily in a condition, for example of an `if` or `while` statement. If the stream does not have the `fail` bit set, the next line from the stream is put into the `std::string`.


