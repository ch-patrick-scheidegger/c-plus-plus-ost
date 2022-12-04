#include <fstream>
#include <memory>
#include <ostream>
#include <sstream>

auto os_factory(bool file) -> std::shared_ptr<std::ostream> {
  using namespace std;

  if (file) {
    return make_shared<ofstream>("hello.txt");
  }
  return make_shared<ostringstream>();
}

auto main() -> int {
  auto out = os_factory(false);
  if (out) {
    (*out) << "Hello world\n";
  }

  auto fileout = os_factory(true);
  if (fileout) {
    (*fileout) << "Hello, world!\n";
  }
}
