# TODO: UPDATE

# Exercises Week1

Goals of this weeks exercises:

* You will setup your development environment for C++.
* You will create and run your first executable project
* You will split a project into a library, test and executable project

## Setup Your Environment

This week we are setting up your laptops and you will exercise to use Visual Studio Code and a C++ compiler. Check the setup instructions here: [Setup Instructions](https://gitlab.ost.ch/cxx/cpl/-/wikis/Setup-Development-Environment-(VSCode))

You can use a different environment like CLion or Visual Studio if your are comfortable in exploring them on your own.


## Exercises

In this week you will reproduce all example programs in chapter 0 of Lucid C++ set up the corresponding projects and compile and run the programs. You can find the chapter [here](https://gitlab.ost.ch/cxx/cpl/-/wikis/Lucid-C---Book). Note that the book is targeting Cevelop as a development envrionment. Unfortunately, we needed to change the tooling for this module as C++20 is not supported well enough by Cevelop. When you have accomplished these exercises you will:

 - Be familiar with setting up and building C++ libraries
 - Be able to split a simple application into:
   - Library Project
   - CUTE Test Project
   - Executable Project
 - Have implemented a testable hello world application in C++
 - Have learned how to implement a unit test for a function using `std::ostream`
 - Have implemented your first simple class

 **Note:** You don't need to have any VSCode extensions for these exercises. We have a list of recommended exercises in this repository, which we will use from next week on.


### Manual Hello World

While in exercises in the upcomming weeks you will work with the git repository provided on gitlab, we will start with a clean workspace for now. Visual Studio Code does not provide inherent capabilities for compiling C++ programs as an IDE might support. Therefore, we rely on CMake to help us.

First we want a simple program to be compiled an run.

- Open a fresh workspace, i.e. any empty folder with VSCode
- Add a new file `HelloWorld.cpp` on top-level
- Insert the code for printing `Hello World!` on the standard output. You can copy paste the following snippet:

```cpp
#include <iostream>

auto main() -> int {
    std::cout << "Hello World!\n"
}
```

As stated above, VSCode will not be able to create an executable program on its own from that file alone. We can do this manually:
- Open a terminal (within VSCode) 
- Run `g++ HelloWorld.cpp`
- There will be no output if the compilation was successful. However, if you just copied the snippet from above, the compiler will not be happy. It will show an error message like the following:
```
HelloWorld.cpp: In function 'int main()':
HelloWorld.cpp:4:34: error: expected ';' before '}' token
    4 |     std::cout << "Hello World!\n"
      |                                  ^
      |                                  ;
    5 | }
      | ~
```
- Reading and understanding compiler output is might be crucial when programming. Sometimes, it is even helpful and understandable. As in the case above it savily found the missing semicolon. Hint: Keeping in mind the different steps of the compilation process (preprocessor, compiler, linker) can help understanding the problem while building a project.
- For now, just fix the error (depending on the extenions installed in VSCode, you will even get a quick-fix) and compile again.
- If the compilation was successful, the compiler create an executable program `a.out`/`a.exe`.
- Run the program from the terminal: `./a.out` or `./a.exe` and observe the output.

**Hoorray! You did it! You successfully compiled and run a C++ programm...**


### Hello CMake

Compiling and running programs from the terminal is simple if there is only a single source (.cpp) file. However, real projects consist of dozens, hundres or even thousand source and header files, which obviously need to be structured into well digestable chunks - libraries. Still the individual commands become very long quickly, as we need to specify which source files to compile, where to look for included headers (include paths), what libraries to use and where to search them. Obviously, typing all required compiler commands into a terminal manually becomes unmanagable and must be automated. Typically, a script for a build tool containing the required commands would be written. 

Tools like `Ninja` and `Make` perform such tasks quite well. However, they usually require the commands for a specific compiler toolchain, like GCC, clang or MSVC. They all have different executable names and require different arguments, even if the functionality is similar. Swtiching toolchains can subsequently be difficult. To circumvent this problem we facilitate the meta-build system `CMake`. You should already have installed it at the beginning.

You can check your CMake installation by running `cmake --version` in a terminal.

#### Your CMake Project

CMake instructions are usually put into `CMakeLists.txt` files. CMake will interpret them and generate the files for the selected build tool and compiler toolchain, when it is configured.

Create a new file named `CMakeLists.txt` into your workspace.
Put the following content into the file:

```
cmake_minimum_required(VERSION 3.19)

# Basic project configuration
project("CPl W01"
    LANGUAGES CXX
)

# Set c++ language standard to C++20
set(CMAKE_CXX_STANDARD 20)


# Specify executable "HelloWorld" (target)
# to be built from source file "HelloWorld.cpp"
add_executable("HelloWorld"
    "HelloWorld.cpp"
)
```

CMake needs a directory to work in as the whole compilation process creates many artifacts. Typically, such a directory will be in your `.gitignore` file to avoid checking in any binaries. Create a new directory called `build` in your workspace.

Then run the command to configure the CMake project: `cmake -B build`
This command will configure the CMake project and use the `build` directory to put all files it creates in that process. By default it will try figure out automatically which build tool and compiler toolchain to use. If necessary you can also specify them with the options `-G Ninja` (for the Ninja build tool) and `-D CMAKE_CXX_COMPILER=g++` (for the GCC C++ compiler).

Now, the build files should have been written and could be inspected in the `build` directory. Next we would like to run the compilation: `cmake --build build`

This should build the project configured in the `build` directory. If successfull you will see the resulting `HelloWorld` executable there.

Run it and check the output to see if it worked.



### Proper Project Structure

If you face a programming task, you might instinctivly want to create a new executable containing a main that maybe takes some input from the console and prints a result to the standard output. That is fine for tasks that have a complexity comparable to a Hello World application (no input at all). Beyond that a professional software engineer would write a programm to check if their code works correctly. Specifically, you should write automated tests using some testing framework to perform this task.

In Java and other languages that are executed on a virtual machine, you can easily squash multiple executables and various unit tests into a single project and then just select in your IDE what to run. In C++ (with CMake) you are forced to be a bit more structured and specify what libraries and executables exist and how the depend on each other.

Our recommendation for a default project structure looks as follows:
- One (or more) libraries that contain the actual logic you need to implement, i.e. the task you want to solve.
- For each library a test executable project, to test the functionality of the library with multiple unit tests possibly structured into individual test suites. Note that there needs to be an explicit executable (with a main() function) in C++ to run the tests.
- Optionally, a (command line) executable to allow user-interaction. This usually is a very, very, simple C++ source file, containing a main() function and just calling the primary entry point of the library used with `std::cin/std::out` as arguments. The functionality put into the `main()` function must be simple, as there is no way to test the content of a main programm from within C++. So you could not write unit tests for its logic.


#### Create the Hello Library

Creating a library should be your first step when starting a fresh task. A library can constist of multiple object files, each created from a `.cpp` source file. The interface of the library is specified in `.hpp` header files, that will be included by the implementing source files and also by the files depending on it (possibly in other libraries or executables).

You should now create a library for the Hello World functionality. Typically, Hello World programs print the text "Hello World!" to the console. Testing console output in C++ (`std::cout`) is not possible easily. Therefore, we need an abstraction to be used on the interface of the Hello library, which we will also be able to write a unit test for.


##### The `Hello.hpp` Header File

In this case we can use the more general `std::ostream` as a parameter of our function printing "HelloWorld!" instead of directly using the global object `std::cout` in the function. The function signature looks as follows: `auto sayHello(std::ostream& out) -> void;`

This function declaration is put into a header file, also containg the include guard and the necessary include directive telling the compiler that `std::ostream` exists. Create a new directory `lib` in your workspace and put a file `Hello.hpp` into it. The contents of the file should be the following:

```
#ifndef HELLO_HPP_
#define HELLO_HPP_

#include <iosfwd>

auto sayHello(std::ostream& out) -> void;

#endif
```

Details what the header file contains:
* The include guard, which prevents the file's content to be muliplied when included more than once.
* The include directive for [`<iosfwd>`](https://en.cppreference.com/w/cpp/header/iosfwd), which contains the declaration (not the definition) of various stream types like `std::ostream` and `std::istream`.
* The declaration of the `sayHello` function. It takes an `std::ostream` by reference (`&`) as we want the side-effect of writing to it be visible at the call-site and `std::ostream` cannot be copied anyway. So it would not be useful to take an `std::ostream` by value.


##### The `Hello.cpp` Source File

The library must also contain the implementation of the `sayHello` function, which would be defined in a C++ source file (`.cpp`). Please create the corresponding `Hello.cpp` file in the `lib` directory. It should have the following content:

```
#include "Hello.hpp"
#include <ostream>

auto sayHello(std::ostream& out) -> void {
    out << "Hello Wordl!\n";
}
```

Details what the source file contains:
* The include directive `#include "Hello.hpp"`. This will make the name `sayHello` available in this source file. At the moment this would not even be necessary, as the definition of the `sayHello` function is also a declaration. Subsequently, you have to be aware, that a spelling mistake in the function name might be unrecognized, until the linker tries to resolve the function and cannot find it due to the incorrect name. Having the include of `Hello.hpp` here is beneficial nevertheless. It is good practice that the own header (`XYZ.cpp` -> `XYZ.hpp`) is included first, which ensures it is self-contained (as it is parsed first).
* The include directive `#include <ostream>`. This contains the definition of `std::ostream` and the required output operator (`<<`). You spot the difference of include styles `"header"` vs `<header>`. The first is usually used for the programmer's include files, while the latter is used for includes of the standard library. However, this difference is actually only conventional, as any toolchain could just specify their own lookup rules for the two distinct kinds of includes.
* Regarding include order: It is good practice to include own-headers (`""`) before system-headers (`<>`).
* The definition of the `sayHello` function. 


##### The `Hello` Library Target in CMake

Since we have the C++ files for creating the library, we now need to tell CMake to actually create it. We still work in the top-level `CMakeLists.txt`. Add the following content to the existing file:

```
# Specify library "HelloLib" to be built from
# the "Hello.cpp" file from the "lib" directory
add_library("HelloLib" "lib/Hello.cpp")

# Set the include directory paths for "HelloLib"
# PUBLIC enables dependent targets to also use that include path
target_include_directories("HelloLib" PUBLIC "lib")
```

The `target_include_directories` instruction specifies that the `"lib"` directory should be searched for header files included by include directives. To compile `Hello.cpp` this would actually not even be required, as the `#include "Hello.hpp"` would also resolve the correct header, as it is colocated with the `Hello.cpp` source file and the relative path would be resolved successfully. But any other target depending on the library benefits from it due to the `PUBLIC` specifier.

You can rebuild the project by executing `cmake -build build` again. This will build all targets. You could also build only a specific target, in case of the `HelloLib` by adding the `-t` option: `cmake --build build --target HelloLib`.


#### Create the Hello Test Exectuable

Typically, you would create the implementation only after you have written a test - at least when following the Test-Driven Development approach. Constructing the whole structure bottom-up is easier to follow in a tutorial like this, therefore, we decided to create the library first and then the test. In general you could also start with a test target and develop the functionality in that context and just eventually extract all functionality into a separate library.

To write unit tests for the C++ exercises, we use the lightweight C++ Unit Testing Easier (CUTE) framwork, developed by Peter Sommerlad. It is a header-only framework, which means that it just needs to be included in the test code and does not need to be compiled upfront and linked into your test executable.


##### Add CUTE Library

First, you need to get the CUTE headers. You can copy the folder `CUTE` from the CPl repository's `lib` directory to get them. It contains another folder named `cute`. This might look like a redundancy in the structure, but it is intentional. We will set the `CUTE` folder as include path, which will still allow including the library's headers with a relative path starting with `cute`. For example including the `ostream_listener.h` file with `#include <cute/ostream_listener.h>`. 

After you have copied the `CUTE` folder to your workspace, add the following parts to your top-level `CMakeLists.txt` file:

```
# Specify library "CuteFramework"
# It is a header-only library, featuring no object files
add_library("CuteFramework" INTERFACE)

# Set the include directory paths for "CuteFramework"
# INTERFACE enables dependent targets to also use that include path
target_include_directories("CuteFramework" INTERFACE "CUTE")
```


##### Add CUTE Test

Now we are ready to create the first CUTE test:
* Create a directory named `test` in your workspace. 
* Add a file `HelloTest.cpp` into that directory.
* Copy the following content into that file:

```
#include "Hello.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>

#include <sstream>

TEST(testSayHelloWritesHelloWorldWithNewlineToTheOutputStream) {
  auto output = std::ostringstream{};
  sayHello(output);
  ASSERT_EQUAL("Hello World!\n", output.str());
}

auto createHelloSuite() -> cute::suite {
  cute::suite helloSuite{};

  helloSuite += testSayHelloWritesHelloWorldWithNewlineToTheOutputStream;

  return helloSuite;
}

auto main(int argc, char const *argv[]) -> int {
  cute::ide_listener<> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto helloSuite = createHelloSuite();

  bool suiteResult = runner(helloSuite, "Hello Suite");

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

As you can see a CUTE test program is an executable featuring a `main()` function like any other programm. Please read through the code and try to follow the logic. Not everything might be clear at this point. The important parts are that you can ...
* ... identify the `main()` function as entry point. 
* ... see where the test case is added to the suite. CUTE always requires a suite, but cannot have nested suites so far.
* ... find the test case. It calls `sayHello`. Instead of supplying the standard output `std::cout`, it creates a local `std::ostringstream` object (an `std::ostream` that is string based), which and stores the content wirtten to it. That content can then be queried with `.str()` and compared to the expected value.


To build the test executable you can append the following instructions to you `CMakeLists.txt`:

```
# Specify the "HelloTest" executable
# It is built from the "test/HelloTest.cpp"
add_executable("HelloTest" "test/HelloTest.cpp")

# Set the library depencies of "HelloTest"
# It depends on the "HelloLib" which it tests and the "CuteFramwork"
# for its headers
target_link_libraries("HelloTest" PRIVATE "HelloLib" "CuteFramework")
```

You can again build everything with: `cmake --build build`
And then run the test: `.\build\HelloTest.exe` - on Linux and MacOS without the `.exe` sufix.

If you have not already recognized the mistake in the library implementation we provided above, you should see an output like the following:

```
#beginning Hello Suite 1

#starting testSayHelloWritesHelloWorldWithNewlineToTheOutputStream

#failure testSayHelloWritesHelloWorldWithNewlineToTheOutputStream C:/Users/thali/Documents/cpl-new-workspace/test/HelloTest.cpp:13 testSayHelloWritesHelloWorldWithNewlineToTheOutputStream_IMPL: "Hello World!\\n" == output.str() expected: Hello World!\n  but was:        Hello Wordl!\n

#ending Hello Suite
```

It is awesome that we wrote a test! Otherwise, we might never have recognized the flipped letters in `Wordl`.
Correct the error and try again until your test runs successfully.

The output would look as follows:

```
#beginning Hello Suite 1

#starting testSayHelloWritesHelloWorldWithNewlineToTheOutputStream

#failure testSayHelloWritesHelloWorldWithNewlineToTheOutputStream C:/Users/thali/Documents/cpl-new-workspace/test/HelloTest.cpp:13 testSayHelloWritesHelloWorldWithNewlineToTheOutputStream_IMPL: "Hello World!\\n" == output.str() expected: Hello World!\n  but was:        Hello Wordl!\n

#ending Hello Suite
```


#### Create the Hello Executable

As we know now that the library implementation is correct, we can create a programm to be shipped to millions of excited users:
* Create a folder `app` in your workspace
* Add a file `HelloApp.cpp` into that folder
* Copy the following content into the file:

```
#include "Hello.hpp"

#include <iostream>

auto main() -> int {
    sayHello(std::cout);
}
```

The `main` programm should always be as simple as the program above and only consist of a single statement, which is the call of the library. In this case `sayHello`. If standard input and/or output streams are required, `std::cin` and `std::cout` can be supplied.

Try to extend the `CMakeLists.txt` file on your own first. You need to create a new executable that depends on the `HelloLib`.



### Summary

You should now understand the basic structure of a C++ project and are able to create simple library and (test) executable targets in CMake.

You can find more information about CMake on the corresponding website and their tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
Note: We will not focus on CMake in detail. Usually, we will provide the required project setup for you.

---
keywords:
- c++
title: 'Introduction / Project Structure'
---
