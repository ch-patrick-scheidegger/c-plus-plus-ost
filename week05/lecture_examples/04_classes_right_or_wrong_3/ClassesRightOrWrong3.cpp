
#include <istream>

struct SwissGrid {
  SwissGrid() = default;
  SwissGrid(double y, double x);
  auto read(std::istream& in) -> void {
    double y{}; in >> y;
    double x{}; in >> x;
    try {
      SwissGrid inputCoordinate{y, x};
      *this = inputCoordinate;
    } catch(std::invalid_argument const& e) {
      in.setstate(std::ios_base::failbit);
    }
  }
private:
  double y{600000.0};
  double x{200000.0};
};

auto operator>>(std::istream& in,
                SwissGrid& coordinate) -> std::istream& {
  coordinate.read(in);
  return in;
}
