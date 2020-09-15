# Module: C++ in HS20

This repository contains all materials for the C++ (CPl) modules at OST.
We use the [`TS-CPl-HS20`](https://teams.microsoft.com/l/team/19%3aee9d1b0dc838423686a103f7b8cbf2c9%40thread.tacv2/conversations?groupId=40fb7d97-bf4e-48c6-b28c-681a2d2fdf04&tenantId=a6e70fa3-1c7a-4aa2-a25e-836eea52ca22) channel on the OST MS Teams instance.
Lectures will be available on [Switch Tube](https://tube.switch.ch/channels/889a82a4).

## Goal

In the course of this module students learn usage and understanding of modern C++.

Code examples in the lecture and exercises target the current C++ standard, also known als C++17.
A pre-version of the language standard can be found [here](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf).
This working draft lacks only minor editorial fixes compared to the official standard.

A much more accessible reference to the standard document exists in [cppreference]( https://en.cppreference.com/w/)

## Cevelop

We strongly recommend to use the [Cevelop](https://www.cevelop.com) for our C++ courses.
While it is possible to use other IDEs, only Cevelop is:

- platform independent
- free to use
- provides suitable support for unit testing with [CUTE](https://www.cute-test.com)
- has quality-of-life features like assisted inclusion of standard library headers
- hints about common programming mistakes
- and can visualize template instances

## Lecture Plan and Resources (TBA)

| Week | Lecture                                                           | Plan | Exercise                                                                                | Topics                                                 | Remarks        |
|------|-------------------------------------------------------------------|------|-----------------------------------------------------------------------------------------|--------------------------------------------------------|----------------|
| 38   | [Slides](week01), [Video](https://tube.switch.ch/videos/41b34752) | COT  | [E01](week01/README.md) ([PDF](/../-/jobs/artifacts/master/file/week01.pdf?job=week01)) | Introduction                                           |                |
| 39   | [Slides](week02), [Video](https://tube.switch.ch/videos/af786ac1) | COT  | [E02](week02/README.md) ([PDF](/../-/jobs/artifacts/master/file/week02.pdf?job=week02)) | Values                                                 |                |
| 40   | [Slides](week03), [Video](https://tube.switch.ch/videos/0216adb3) | COT  | [E03](week03/README.md) ([PDF](/../-/jobs/artifacts/master/file/week03.pdf?job=week03)) | Sequences and Iterators                                |                |
| 41   | [Slides](week04), [Video](https://tube.switch.ch/videos/ffb06a12) | COT  | [E04](week04/README.md) ([PDF](/../-/jobs/artifacts/master/file/week04.pdf?job=week04)) | Functions and Exceptions                               | **Testat 1**   |
| 42   | [Slides](week05), [Video](https://tube.switch.ch/videos/3f9e7d90) | COT  | [E05](week05/README.md) ([PDF](/../-/jobs/artifacts/master/file/week05.pdf?job=week05)) | Classes and Operator Overloading                       |                |
| 43   | [Slides](week06), [Video](https://tube.switch.ch/videos/cb762743) | COT  | [E06](week06/README.md) ([PDF](/../-/jobs/artifacts/master/file/week06.pdf?job=week06)) | Namespaces, Arithmetic Overloading, Enums              |                |
| 44   | [Slides](week07), [Video](https://tube.switch.ch/videos/a00095cb) | COT  | [E07](week07/README.md) ([PDF](/../-/jobs/artifacts/master/file/week07.pdf?job=week07)) | Standard Containers                                    |                |
| 45   | [Slides](week08)                                                  | MOF  | [E08](week08/README.md) ([PDF](/../-/jobs/artifacts/master/file/week08.pdf?job=week08)) | Algorithms                                             | **Testat 2**   |
| 46   | [Slides](week09)                                                  | MOF  | [E09](week09/README.md) ([PDF](/../-/jobs/artifacts/master/file/week09.pdf?job=week09)) | Function Templates                                     |                |
| 47   | [Slides](week10)                                                  | MOF  | [E10](week10/README.md) ([PDF](/../-/jobs/artifacts/master/file/week10.pdf?job=week10)) | Class Templates(1)                                     |                |
| 48   | [Slides](week11)                                                  | MOF  | [E11](week11/README.md) ([PDF](/../-/jobs/artifacts/master/file/week11.pdf?job=week11)) | Class Templates(2)                                     | **Testat 3**   |
| 49   | [Slides](week12)                                                  | MOF  | [E12](week12/README.md) ([PDF](/../-/jobs/artifacts/master/file/week12.pdf?job=week12)) | Heap Memory, Smart Pointers                            |                |
| 50   | [Slides](week13)                                                  | MOF  | [E13](week13/README.md) ([PDF](/../-/jobs/artifacts/master/file/week13.pdf?job=week13)) | Dynamic Polymorphism, Variant                          |                |
| 51   | [Slides](week14)                                                  | MOF  | [E14](week14/README.md) ([PDF](/../-/jobs/artifacts/master/file/week14.pdf?job=week14)) | TBD                                                    |                |

### Useful Links

Language References:
- CPP Reference: https://www.cppreference.com/
- CPlusPlus.com: http://www.cplusplus.com
- MSDN Langauge Reference: https://docs.microsoft.com/en-us/cpp/cpp/cpp-language-reference
- MSDN Standard Library Reference: https://docs.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-reference

Online Compilers:
- Godbolt: https://godbolt.org/
- Wandbox: https://wandbox.org/

Links from the Lecture:
- Structured Bindings: https://skebanga.github.io/structured-bindings/
- Problems with Move Semantics (You Tube): https://www.youtube.com/watch?v=PNRju6_yn3o
- Rvalue References and Move Semantics: http://thbecker.net/articles/rvalue_references/section_01.html
- Too Perfect Forwarding: https://akrzemi1.wordpress.com/2013/10/10/too-perfect-forwarding/
- Fun with Blinky (You Tube): https://www.youtube.com/watch?v=6pmWojisM_E
- Reading Declarations: https://cdecl.org/
- Overhead of Dynamic Dispatching: http://eli.thegreenplace.net/2013/12/05/the-cost-of-dynamic-virtual-calls-vs-static-crtp-dispatch-in-c
- Long Compile-Times with Template Meta Programming: http://cpptruths.blogspot.ch/2005/11/c-templates-are-turing-complete.html

IDE and Compilers:
- Cevelop: https://www.cevelop.com
- MinGW (from STL): https://nuwen.net/mingw.html
- MSYS2: https://www.msys2.org/
- CMake: https://cmake.org/

Libraries:
- Boost Library: https://www.boost.org/
- Boost Units: https://www.boost.org/doc/libs/1_74_0/doc/html/boost_units/Units.html
- ASIO: https://think-async.com/Asio/ 
- SFML: https://www.sfml-dev.org/

Collection of C++ Resources:
- https://github.com/MattPD/cpplinks

Exercises with Solutions
- The Modern C++ Challenge (Available only at HSR internally): https://ebookcentral.proquest.com/lib/fh-ostschweiz/detail.action?docID=5400397&query=bancila

---
keywords:
- c++
title: 'C++ Advanced: Module overview'
---

