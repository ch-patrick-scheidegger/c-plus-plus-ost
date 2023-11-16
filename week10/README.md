# Catch up with previous exercises

We expect that you all worked hard on the testat hand-in so that other exercises from the past weeks where not worked on deeply enough yet.
Please solve the function template exercises from last week and play around with the `Sack` template class presented in the lecture.

## Algorithm Trivia

If you still haven't completed it yet, this might be a good time to solve some more of the algorithm trivia exercises.

# 1 exercise: examine and extend Sack<T>

Take the example code including unit tests of the class template Sack

* Can you invent more and better test cases for Sack?
* Does `Sack<Word>` using your Word class work?
* `std::string_view` has similar problems than `char const *` and can lead to dangling of the content of `Sack<std::string_view>`. Implement a template specialization for that case as we did for char const * in the lecture. Try a variant with implementing the body yourself and a variation where you inherit from `Sack<std::string>`.
* What other standard library relationship types might give you similar dangling problems than pointers?
