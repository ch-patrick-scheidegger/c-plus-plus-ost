#ifndef ROTATE3ARGUMENTS_HPP_
#define ROTATE3ARGUMENTS_HPP_


//TODO Add your definition of the rotate3arguments function template here
template<typename T>
auto rotate3arguments(T& first, T& second, T& third) -> void {
    T temp = first;
    first = second;
    second = third;
    third = temp;
}

#endif
