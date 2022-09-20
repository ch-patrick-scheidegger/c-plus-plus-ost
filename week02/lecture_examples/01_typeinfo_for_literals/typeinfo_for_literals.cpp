
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>

#include <boost/type_index.hpp>

// no need to understand, variadic template with forwarding.
template <typename T>
auto showTypeInfoAndValue(std::ostream &out, T const &x) -> void {
  out << x << " is of type " << boost::typeindex::type_id<T>().pretty_name()
      << '\n';
}
template <typename... AllTypes>
auto showTypeInfo(std::ostream &out, AllTypes const &...values) -> void {
  (..., showTypeInfoAndValue(out, values));
}

auto main() -> int {
  using namespace std::string_literals;
  showTypeInfo(std::cout, 'a', '\n', '\x0a', 1, 42L, 5LL, 1u, 42ul, 5ull, 020,
               0x1f, 0XFULL,
               /*0f is a syntax error */ 0.f, .33, 1e9, 42.E-12L, .3l, "hello",
               "\012\n\\", R"(\root.hsr\skripte\)", "hello"s);
  std::cout << "------\n";
  showTypeInfoAndValue(std::cout, 'a');
  showTypeInfoAndValue(std::cout, 42L);
  showTypeInfoAndValue(std::cout, 0xFULL);
  showTypeInfoAndValue(std::cout, R"(\root.hsr\skripte\)");
  showTypeInfoAndValue(std::cout, 1 / 0.0);
  showTypeInfoAndValue(std::cout, 0.0l / 0.0l);
}
