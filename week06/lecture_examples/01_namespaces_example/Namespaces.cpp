namespace demo {
auto foo() -> void; //1
namespace subdemo {
auto foo() -> void {/*2*/}
} // namespace subdemo
} // namespace demo

namespace demo {
void bar() {
  foo(); //1
  subdemo::foo(); //2
}
}

void demo::foo() { /*1*/ } // definition

auto main() -> int {
  using demo::subdemo::foo;
  foo(); //2
  demo::foo(); //1
  demo::bar();
}
