# 0 Catch Up

Chances are high that you haven't been able to solve all exercises from the previous weeks due to the testat. So first complete the remaining non-extra exercises you missed.

# 1 Date with enum for Month and Weekday

The class `Date` from the lecture examples is confusing to use, because we specify day, month and year as numbers. Change the `Date` class from the template to use an `enum` type for month.

* Is it possible to provide the overloads of `Date`'s constructors to allow writing `Date{1, Nov, 2012}` and `Date{Nov, 1, 2012}`? 
* Implement a member function `dayOfWeek()` for your `Date` class that calculates if a given date is `Monday`, `Tuesday` etc. Define a corresponding `enum` type within the `Date` class.
  * Should this be an `enum class` or is an `enum` sufficient? 

*Hint:* Consult [Wikipedia](https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week) to figure out how to calculate the day of the week with your calendar. Note, that we only support Gregorian dates.

## (Optional) Different Representation

Maybe another internal representation than 3 numbers for day-month-year, like the number of days since the start of your calendar makes it easier to implement this feature. Even though this might require change to other member functions, but your test cases should help you keep those working. Try also to implement this more compact date representation.

# 2 Simulated Switch with Toggle Button

To exercise an enum type with hidden values we implement a class `Switch`. The `Switch` simulates three states: `off`, `on`, `blinking`. It comes with a single button simulated with the member function `pressButton()` that switches from `off` to `on` to `blinking` and then to `off` again. Do not expose the enum values in your `Switch.h` file. 

# 3 Finite Field Modulo 5

In this exercise you have to implement a finite field (galois field/endlicher Koerper). You can take the code of `Ring5` from the lecture as a starting point. Beyond the addition and multiplication a `Ring5` features, you should add the following functionality:

* Provide subtraction as inverse of addition.
  * Can it be mapped directly to integer subtraction?
  * `a - a = 0`
  * `3 - 4 = 4 <=> 4 + 4 = 3`
* Provide unary minus operator for negation
  * `a + (-a) = 0`
* Provide division as inverse of multiplication.
  * First figure out for each `x` (excluding `0`), what `y` provides `1 / x = y -> 1 = x * y`
  * Does it make sense to provide relational operators for `Field5`?

## Simplification with Boost

Remove all operator implementations you can replace with Boost operators.

* If you don't already have it, install it first on your system.
* Have a look at the documentation for [Boost operators](https://www.boost.org/doc/libs/1_71_0/libs/utility/operators.htm)
* Apply Boost operators to your `Field5`
 
# 5 (Optional) Ring Modulo 6

Implement a class `Ring6` that implements modulo arithmetic for unsigned integers modulo `6`.

* Start out with corresponding test cases, before you implement an operation.
* Provide addition and multiplication operators.
* Provide output operator to a stream.
* Provide inward and outward conversion from unsigned integers.
  * When is it useful to make these conversions explicit? 
* Is it useful to implement subtraction for `Ring6`?
* Is it useful/possible to implement division for `Ring6`? 
 
