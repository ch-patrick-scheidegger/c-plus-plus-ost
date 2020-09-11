#ifndef ADL_H_
#define ADL_H_



namespace one {
  struct type_one{};
  void f(type_one){/*...*/}
}

namespace two {
  struct type_two{};
  void f(type_two) {/*...*/}
  void g(two::type_two) {/*...*/}
  void h(one::type_one) {/*...*/}
}

void g(two::type_two) {/*...*/}





#endif /* ADL_H_ */
