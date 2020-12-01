#include <iostream>

struct Base {
  int member{};
  explicit Base(int initial) :
      member{initial}{}
  virtual ~Base() = default;
  virtual void modify() { member++; }
  void print(std::ostream & out) const;
};

struct Derived : Base {
  using Base::Base;
  void modify() {
    member += 2;
  }
};

void modifyAndPrint(Base base) {
  base.modify();
  base.print(std::cout);
}

int main() {
  Derived derived{25};
  modifyAndPrint(derived);
}

void Base::print(std::ostream & out) const{
	out << member;
}
