#include <iostream>

struct Base1 {
  explicit Base1(int value) {
    std::cout << "Base1 with argument " << value << "\n";
  }
};

struct Base2 {
  Base2() { std::cout << "Base2\n"; }
};

class DerivedWithCtor : public Base1, public Base2 {
  int mvar;
public:
  DerivedWithCtor(int i, int j) 
      : mvar{j}, Base2{}, Base1{mvar} {} // CAUTION UB!
};

int main() {
  DerivedWithCtor dwc{1, 2};
}
