#include "sumi.h"

#include <istream>
#include <iterator>
#include <numeric>

int sumi(std::istream &is) {
	using input=std::istream_iterator<int>;
	input eof{};
	return std::accumulate(input{is}, eof, 0); //if available std::reduce(input{is}, eof, 0);
}
