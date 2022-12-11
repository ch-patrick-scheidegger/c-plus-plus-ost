
## Theory Questions

*  Your class `Derived` is derived from the class `Base`. You have hidden the member function `process(int)` from your base class (`Base::process(int)`) with the member function `process(float)` (`Derived::process(float)`). How can you make the hidden member function visible again in your derived class?

  * **SOLUTION**: We would need to explicitly inherit the function overload set using the following declaration: `using Base::process`.

*  Given the following code:

```
struct Base {
  void function() const{}
};

struct Derived : Base {
  void function(){}
};

void call_function(Base b) {
  b.function();
}

int main() {
  Derived d{};
  call_function(d);
  Base b{};
  call_function(b);
}
```

What changes are required to the code above in order to have the member function **function()** of the type **Derived** called (in `void call_function(Base b)` for the statement `call_function(d);`)?

**SOLUTION**: We would need for first make the function `Base::function` `virtual` and then change the parameter of `call_function` into a reference.

*  Explain what a pure virtual member function is. What are the implications of having one?

  * **SOLUTION**: pure virtual member functions are virtual functions which are declared using `= 0`. Having a pure virtual member function makes the class abstract, thus prohibiting its instantiation.

*  How can you store shapes (`shape` is the base class and can have derived classes like `square` and `diamond`, see exercise below) in a `std::vector` without producing memory leaks or object slicing?

  * **SOLUTION**: one possible solution would be to use a smart-pointer to the base (e.g. `std::shared_ptr<shape>`) to store the shapes in the vector. Such a smart-pointer instance should be created using the appropriate factory function (e.g. `std::make_shared`).

<hr/>
