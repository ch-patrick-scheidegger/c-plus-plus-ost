## 1 Repetition Week 10
### Static or Dynamic Errors?
When will a template be instantiated? 
**SOLUTION:** The compiler will instantiate templates at compile-time, thus preventing compilation if there are errors.

### Template Definition
Where do you define a class template and its members?
**SOLUTION:** Since the compiler must be able to generate the code for the instantiation at compile-time, we need to define a class template and its members completely within a header file.

### Dependent Types
If you have a member type of another type depending on a template parameter, how do you have to refer to that type?
**SOLUTION:** In order to use a member type of another type depending on a template parameter, we need to tell the compiler that it is in fact a type by using the keyword `typename`.

### Inheritance
How do you refer to members inherited from a dependent type within a class template?
**SOLUTION:** Since the compiler does not implicitly consider the dependent base during name-lookup, we need to specify that we want to use a member of the dependent class explicitly. We can do that by either using the syntax `this->name_of_the_member` or `name_of_derived_class::name_of_the_member`.

### Template Specialization
Is it necessary for a (partial) specialization of a class template to provide the same interface (same member functions) as the unspecialized template?
**SOLUTION:** No. Template specializations are, except for their name, completely unrelated to the template they are specializing and can therefore provide a completely different interface.
