#include <iostream>
#include <memory>

struct Fuel {
  virtual void burn() = 0;
  virtual ~Fuel() { std::cout << "put into trash\n" << std::flush; }
};

struct Plutonium : Fuel {
  void burn() { std::cout << "split core\n"; }
  ~Plutonium() { std::cout << "store many years\n"; }
};

int main() {
  std::unique_ptr<Fuel> surprise = std::make_unique<Plutonium>();
  surprise->burn();
}
