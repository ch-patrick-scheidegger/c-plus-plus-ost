#include <fstream>
#include <memory>
#include <ostream>
#include <sstream>

std::shared_ptr<std::ostream> os_factory(bool file) {
  using namespace std;

  if (file) {
    return make_shared<ofstream>("hello.txt");
  } else {
    return make_shared<ostringstream>();
  }
}

int main(){
  auto out = os_factory(false);
  if (out) {
    (*out) << "Hello world\n";
  }

  auto fileout = os_factory(true);
  if (fileout) {
    (*fileout) << "Hello, world!\n";
  }
}
