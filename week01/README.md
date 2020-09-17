# Exercises Week1

Goals of this weeks exercises:

* You will setup your development environment for C++.
* You will create and run your first executable project
* You will split a project into a library, test and executable project

## Setup Your Environment

This week we are setting up your laptops and you will exercise to use Cevelop and the C++ compiler. We suggest you install Cevelop and a suitable compiler on your system natively for convenience and performance reasons. Check the setup instructions here: [Setup Instructions](https://gitlab.dev.ifs.hsr.ch/lehre/cxx/cpl/-/wikis/Development-Environment)

Of course you can also install Cevelop in a virtual machine environment if you prefer to.

### Ctylechecker & Constificator

We have implemented plug-ins for Cevelop that check your code for various glitches, e.g. missing includes of standard headers and constness of your code. They focus on various issues we usually also criticize in testat exercises. The plug-ins are shipped with the current release of Cevelop (>=1.14.1). If you don't have them yet, you can install them separately:

In the IDE:

  - Open Help->Install new software...
  - Select the following updatesite: https://www.cevelop.com/update/latest
  - Check the Ctylechecker plug-in (in the Beta Plug-ins category).
  - Check the Constificator plug-in (also in the Beta Plug-ins category).

## Exercises

In this week you will reproduce all example programs in chapter 0 of Lucid C++ set up the corresponding Cevelop projects and compile and run the programs. You can find the chapter [here](https://gitlab.dev.ifs.hsr.ch/psommerl/cpp-module/wikis/Lucid-C---Book). When you have accomplished these exercises you will:

 - Be familiar with creating C++ projects in Cevelop
 - Be able to split a simple application into:
   - Library Project
   - CUTE Test Project
   - Executable Project
 - Have implemented a testable hello world application in C++
 - Have learned how to implement a unit test for a function using `std::ostream`
 - Have implemented your first simple class


If you struggle with the first steps in Cevelop, we have a tutorial video showing how to create, build and execute projects in Cevelop. This video also covers the first three of todays exercises. But we encourage you to first try it yourself to achieve a more sustainable learning experience!

[Composing Hello World Projects Video](https://skripte.hsr.ch/Informatik/Fachbereich/C++/CPl/Videos/1.%20composing%20hello%20world%20projects.mp4) (available only internally)

### Hello World

Create a C++ project (Hello World Executable Project) in Cevelop, compile and run Hello World. This is a sanity check for your environment. Please report to your exercise supervisor immediately, if you cannot make this work.

**Note:**

  - In order to build the project you need to have some of its resources selected (the project in the Project Explorer or have a file of that project open in the focused editor) and then click the Hammer icon. This will build your project. The commands executed and the errors (if any) are reported in the `Console` view of Cevelop.
  - To run the (executable) project for the first time, you need to right-click the project in the Project Explorer and select `Run As -> 1 Local C/C++ Application` from the menu.
    - You cannot run the project if you have never built it before (i.e. there must be an executable binary file in the project).
    - Running the project will build it if necessary.
    - Subsequent launches of the executable are accessible through the `Run` button in the tool bar.

### Hello World with separate Compilation Unit

  - Create a single C++ project with [Header](week01/exercise_templates/sayhello.h), [Implementation](week01/exercise_templates/sayhello.cpp) and [Main Program](week01/exercise_templates/mainsayhello.cpp)
  - Compiling the code:
    - Build your project (Hammer icon in Cevelop).
    - Do you get any errors?
    - Read the output in the build console and understand the executed commands. You should be familiar with similar compiler calls from the Bsys module.
  - Breaking the code:
    - What happens, when you remove the `#include` preprocessor directives from either the main program or the sayhello source file?
    - Remove the declaration  from `main()`. The declaration of `sayHello()` is located in the header file, i.e. you remove the declaration of the function if you delete the `#include`.
    - Remove the include guard from the header file `sayhello.h` and include the file twice in the corresponding main program `mainsayhello.cpp`. Do you expect an error? Do you get one? Why?
    - Since `sayHello()` is a function, you can call it from itself (`sayhello.cpp`). What happens if you call it after the output statement? What happens if you call it in front of the output statement? Why does this happen?
      -  On Linux or Mac you should limit the stack size using `ulimit -s 32` before you run your change program or better run it in a debugger
    - Experiment with the code by applying small modifications to prevent the compilation from succeeding. See what happens in Cevelop and when you try to build your project. Try to understand the error messages.

### Hello World Library Project and Unit Test

  - Create a C++ **Static** Library Project with Cevelop that consists of the files from above.
  - Compile it.
  - Create a CUTE Test Project in your Cevelop Workspace that depends on the above library project. You can select the dependency in the `New Project` wizard on the second page (click `Next` instead of `Finish`.)
  - Change the test case in the generated Test.cpp that it actually executes `sayHello()` using a `std::ostringstream` object os. Verify the result using 

```cpp
  ASSERT_EQUAL("Hello, World!\n", os.str())
```

  - Can you make the test fail, can you make the test succeed?
    - what do you observe in the CUTE test viewer. Can you navigate to the failing test case? Can you compare the results if the test fails?
    - If unsure how to use it, try to access the documentation of CUTE test plug-in. Where is it?
  - Why don't you violate the One-Definition-Rule with the second `main()` function in the library?

### Hello World Class

  - Read chapter *0.6 A First Class* of the [Lucid C++ Book](https://gitlab.dev.ifs.hsr.ch/psommerl/cpp-module/wikis/Lucid-C---Book) material first.
  - Create a `C++ Static Library Project` for your first class `Hello`.
  - Add the class definition to a new header file `Hello.h`
  - Add the member function implementation to an implementation file `Hello.cpp`
  - Create a `CUTE Library Test Project` to actually test your class `Hello`.

Breaking the code:
  - Remove the include guard and add another `#include` for the file `Hello.h` containing the class `Hello`. Do you expect an error? Do you get one? Why?
  - What happens when you compile `Hello.cpp` without the implementation file containing the definition of `sayHello()`? Can you explain the error message?

### Main for Hello World Class

Create a separate empty exexutable C++ project (`HelloMain`) that depends on your library class `Hello`. Add a C++ source file to that new project (`helloclassmain.cpp`) and use your `Hello` class there (descriped in chapter 0.6 of the book, it corresponds to `hello3.cpp`). To be able to compile that file using the library, you need to set in the `project's properties->C++ General->Paths and Symbols` on the following tabs the corresponding entries (The CUTE Library Project wizard will do that for you):

  - Includes: add to GNU C++ the project Hello as a workspace path
  - Libraries: add `Hello` as the library (-> file will be `libHello.a`)
  - Library Paths: add `/Hello/Debug` as a workspace path
  - Referencs: tick the Hello project as referenced project (Active configuration) 
  - See: [Adding a Library Dependency](https://gitlab.dev.ifs.hsr.ch/psommerl/cpp-module/wikis/Adding-a-Library-Dependency)


### Common Problems

 - Project Setup
    - Unresolved include to header file:
      - Check spelling of header name.
      - The referenced include path must be correct (In properties of referencing `project -> C/C++ General -> Paths and Symbols -> Includes -> GCC C++` 
      - Add include to the path of the header file - specifically, if the header file is located in the `src` directory, that path has to be specified).
  - Error in Cevelop
      - Check type of error (See [Warnings and Errors](https://gitlab.dev.ifs.hsr.ch/psommerl/cpp-module/wikis/warnings_and_errors_in_cevelop)). There different kinds of errors, but generally the compiler is always right!
      - Type cannot be resolved / incomplete type:
          -  Check whether there is an include for this type. E.g. `std::ostringstream` with include to `<sstream>`.

### Other Resources

If you like to have a German introduction to Eclipse CDT (which Cevelop is based on), you can refer to the extensive guide by Gerd Hirsch: http://www.gerdhirsch.de/downloads/Eclipse/EclipseCDTSchulung.pdf

---
keywords:
- c++
title: 'Introduction / Cevelop installation'
---
