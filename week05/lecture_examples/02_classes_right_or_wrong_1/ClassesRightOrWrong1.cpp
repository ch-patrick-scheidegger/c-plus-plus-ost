

#include <ostream>

struct Counter {
  auto increase(unsigned step) -> void {
    auto before = current();
    value = before + step;
  }
  auto current() const -> unsigned {
    return value;
  }
private:
  unsigned value;
};

struct Document {
  auto print(std::ostream & out) const -> void {
    // updatePrintDate();
    out << content;
  }
private:
  auto updatePrintDate() -> void { 
  }

  std::string content{};
};


auto main() -> int {
}