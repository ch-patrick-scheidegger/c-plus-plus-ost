#ifndef ADL_HPP_
#define ADL_HPP_

namespace one {
  struct type_one{};
  auto f(type_one) -> void {/*...*/}
} // namespace one

namespace two {
  struct type_two{};
  auto f(type_two) -> void {/*...*/}
  auto g(two::type_two) -> void {/*...*/}
  auto h(one::type_one) -> void  {/*...*/}
} // namespace two

auto g(two::type_two)  -> void {/*...*/}

#endif
