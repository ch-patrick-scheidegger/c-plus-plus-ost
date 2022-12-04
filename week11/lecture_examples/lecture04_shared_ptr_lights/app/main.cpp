#include <iostream>
#include <memory>

struct Light {
  Light(std::ostream & out) : out{out} {
    out << "Turn on\n";
  }

  ~Light() {
    out << "Turn off\n";
  }

private:
  std::ostream & out;
};

auto main() -> int {
  std::cout << "-- creating the original 'Light' shared_ptr...\n";
  auto light = std::make_shared<Light>(std::cout);
  std::cout << "-- creating the first 'Light' shared_ptr copy...\n";
  auto same = light;
  std::cout << "-- creating the second 'Light' shared_ptr copy...\n";
  auto last = same;

  std::cout << "-- resetting the original 'Light' shared_ptr...\n";
  light.reset();
  std::cout << "-- resetting the first 'Light' shared_ptr copy...\n";
  same.reset();
  std::cout << "-- resetting the second 'Light' shared_ptr copy...\n";
  last.reset();
}
