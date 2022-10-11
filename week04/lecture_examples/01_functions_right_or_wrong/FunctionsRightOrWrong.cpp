
#include <iostream>
#include <string>
#include <vector>

//to make connect() compile
struct Address{};
struct Connection{
    Address address;
};

// auto connect(Address address) -> Connection & {
//   Connection connection{address};
//   //...
//   return connection; //Compiles, but every access at the call-site is UB
// }


// ---------------------

//to make the functions compile
struct Coordinate{};
struct POI{};


auto createPOI(Coordinate) -> POI { return{}; }

auto allPOIs(Coordinate const location) {
  //...
  POI const & migros = createPOI(location);
  //...
  return std::vector{migros};
}


// ---------------------

//to make the functions compile
struct LargeDocument{};


auto modify(LargeDocument & document) -> void;

auto changeDocument() -> void {
  LargeDocument const document{};
//  modify(document); //not allowed
}


// ---------------------


auto print(LargeDocument const & document) -> void {}

auto printAll() -> void {
  LargeDocument document{};
  print (document);
}


// ---------------------

auto max(std::string const & left, 
         std::string const & right) -> std::string const & {
  return (left > right) ? left : right;
}

auto main() -> int {
  std::string const & larger = max("a", "b");
  std::cout << "larger is: " << larger;
}
