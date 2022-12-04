## 0 Indexable Set Class Template (3.TESTAT)

**Hand-in time is Monday 20. Dec 2022, 11:59 (PM) (CET)**

Create a class template `IndexableSet<typename T, typename COMPARE=std::less<T>>` that **inherits** from `std::set<T,COMPARE>` and allows indexing its content like you could do with a `std::vector<T>`. Negative indices should index from the "end" of the set. Provide also member functions `front()` and `back()` that correspond to those of vector.

Write Test cases and implementation code for `IndexableSet` for the following aspects:
*  All constructors available for `std::set` have to work identically for `IndexableSet`
*  Index access (with `operator[]` and `at()`) should reveal the stored values in sorted order
*  Negative indices should index the set from the end, so that `s[-1]` is the last available (the greatest) element in the set and `s[-s.size()] == s[0] `
*  Provide member functions `front()` and `back()`
*  All of your operations that might result in undefined behavior, because an index is out of range, or no elements exist should throw a corresponding standard exception (`std::out_of_range`).
*  Allow instantiating `IndexableSet` with a different compare functor. Demonstrate that with a test case with your own `caselessCompare` functor for `std::string`. (`IndexableSet<std::string, caselessCompare>`)

**Note:**
*  Implement the template class `IndexableSet` as header-only (`indexableSet.hpp`).
*  Remember the rules for class templates inheriting from a class that also depends on a template parameter! Otherwise interesting effects for name lookup might happen. Omitting that will cause you to fail!
*  When inheriting constructors from a base class, you will not inherit the deduction guides. Therefore, you will not be able to omit the class template arguments when using `IndexableSet` in your tests.
<!-- *  We have added the possibility to submit your `IndexableSet` implementation to [ALF](https://alf-uploader.sifs0005.infs.ch/)
  *  You are expected to upload a file named `IndexableSet.h` that contains your template, defined in the global namespace.
  *  We extended the checking automation to catch segmentation faults (program crashes due to illegal memory access) which are likely for this exercise. If your program compiles successfully but the test results print something similiar to what you see below, you should probably check your index acesses:
```
*** Segmentation fault
Register dump:

 RAX: 0000000000000000   RBX: 0000000000000001   RCX: 0000000000aaf540
 RDX: 0000000000000000   RSI: ffffffffffffffff   RDI: 00007ffea1cb7098
 RBP: 00007ffea1cb6fa0   R8 : 0000000000aaecd0   R9 : 00007fb41f637600
 R10: 00000000000003b3   R11: 00007fb41f406ee0   R12: 0000000000aafa40
 R13: 00007ffea1cb7fb0   R14: 0000000000000000   R15: 0000000000000000
 RSP: 00007ffea1cb6f88
``` -->

## 1 Repetition Week 10
### Static or Dynamic Errors?
When will a template be instantiated? 
*  At compile-time
*  At run-time
*  It depends, if the template is specified as **static** it is instantiated at compile-time otherwise at run-time

### Template Definition
Where do you define a class template and its members?
*  In the header file?
*  In the source file?
*  In both the header and the source file?

### Dependent Types
If you have a member type of another type depending on a template parameter, how do you have to refer to that type?

### Inheritance
How do you refer to members inherited from a dependent type within a class template?

### Template Specialization
Is it necessary for a (partial) specialization of a class template to provide the same interface (same member functions) as the unspecialized template?

## 2 A vector with backward indexing using negative indices (Optional)

The goal is to
  - **A.** get familiar with the standard library's container interface and
  - **B.** to exercise writing a template class.

Many scripting languages allow dynamic arrays to be indexed with negative indices where `a[-1] ` denotes the last element in the array `a[size-1]` and `a[-size]` the first element `a[0]`.

Create a template class `DynArray<T>` that uses a `std::vector<T>` as a member (**not as a super class**) for its implementation. Implement the indexing member functions similar to `std::vector` for `DynArray` in a way that negative indices are allowed and every index access is actually bounds checked (use `std::vector`'s facility for that).

*  Provide constructors for the following initialization variants, as it would be with `std::vector` (ignore allocator argument versions of `std::vector`):
    * `dynArray<char> a1{};`
    * `dynArray<int> a2{1, 2, 3, 4, 5}; // initializer_list`
    * `dynArray<double> a3(10, 3.14); // count + value`
    * `dynArray<std::string> a4(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>}); // any iterator type!`

*  Create Unit Tests for all of your template class' behaviors. Best, one or more tests for a feature, before you implement it.
  *  Use different element types for your template class in the tests to prove that it works with different instantiation variants
  *  you must implement your class in a header file (`dynArray.hpp`)

The following functions of std::vector you **should not implement**:
*  allocator template parameter and functions using it
*  `getallocator()`
*  `reserve()`,`max_size()`
*  `operator=()` -- automatically provided one should be OK
*  `assign()`
*  `data()`
*  `shrink_to_fit()`
*  `emplace()`, `emplace_back()`, `insert()`
*  `swap`
*  `comparison operators`
*  all rvalue-reference overloads (unless you want to)

But you must implement all other members of std::vector by delegating to the corresponding member functions of your template class' data member of type std::vector.

## 3 Topological Sorting

Solve the exercise from the OO module in C++ using (smart) pointers to build the graph of objects.
Read dependencies from a file, where the first string provides the current module name and the following strings its pre-requisites.
The file is not sorted, so that modules might be pre-requisites, before you know what pre-requisites theses modules have.
Create a `Module` class with a string and appropriate container `ModuleSort` with `std::shared_ptr` to this class.

--input.txt--
```
DB1 OO
DB2 DB1
Math
OO
AD1 OO
CPI OO Math
Thesis DB2 SE2 UI2
SE1 AD1 CPI DB1
SE2 DB1 SE1 UI1
UI1 AD1
UI2 UI1
```

Expected output:
```
1: Math OO
2: DB1 AD1 CPI
3: DB2 SE1 UI1
4: SE2 UI2
5: Thesis
```

* Build a dependency graph, where each node has a container of `std::shared_ptr` to nodes it depends on.
  Keep a dictionary of all nodes for easy check if a node with a given name was already produced
* Produce an output that assigns a schedule, where each semester only modules are selected, where all pre-requisites are fulfilled.
  Start with those nodes that do not have a pre-requisite.

**Notes:**
* provide a separate `main()` where you can pass the filename as a command line argument.
* Do not produce a memory leak!
* Do not instantiate objects representing the same lecture twice!
* Write unit tests for your functions!

**Optional:**
* Test your code also with the large dependency file: LargeCatalogue.txt
* measure timing as follows (using `#include <chrono>`):
```
    auto start=std::chrono::system_clock::now();
    // do your stuff
    std::chrono::duration<double> delta=std::chrono::system_clock::now()-start;
    out << delta.count() << "s time\n";
```

<!-- *See the "Skripte Server" for details on the old OO assignment:*
https://skripte.hsr.ch/Informatik/Fachbereich/Objektorientierte_Programmierung/OO/Fr%c3%bchere_Vorlesung_HS_2017/%c3%9cbungen/08_Collections_TESTAT2/ -->
