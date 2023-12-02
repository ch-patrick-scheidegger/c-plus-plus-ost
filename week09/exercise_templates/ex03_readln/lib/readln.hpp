#ifndef READLN_HPP_
#define READLN_HPP_

#include <istream>
#include <sstream>

template<typename First>
auto consumeLine(std::istringstream is, First & first) {

}

template<typename First, typename...Types>
auto consumeLine(std::istringstream is, First & first, Types &...rest) -> void {
    is >> first;
    consumeLine(is, rest...);
}

template<typename First, typename...Types>
auto readln(std::istream& in, First & first, Types &...rest) -> void {
    std::string line{};
    std::getline(in, line);
    std::istringstream lineStream{line};
    consumeLine(in, first, rest...);
}

#endif
