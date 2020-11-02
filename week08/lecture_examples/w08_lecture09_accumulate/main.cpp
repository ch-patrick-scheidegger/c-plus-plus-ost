#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <iostream>

int main(int argc, char **argv) {
	std::vector<std::string> long_months { "Jan", "Mar", "May", "Jul", "Aug", "Oct", "Dec" };
	std::string accumulated_string = std::accumulate(
			begin(long_months) + 1, //Second element
			end(long_months),       //End
			long_months.at(0),      //First element, usually the neutral element
			[](std::string const & acc, std::string const & element) {
				return acc + ", " + element;
			});
	std::cout << accumulated_string; //Jan, Mar, May, Jul, Aug, Oct, Dec
}
