#include <vector>
#include <chrono>
#include <iostream>
#include <ostream>
#include <ios>
#include <iterator>
#include <algorithm>

auto contains_with_loop(std::vector<int> const & values, int const v) -> bool {
	auto const end = std::end(values);
	for(auto it = std::begin(values); it != end; ++it) {
		if (*it == v) {
			return true;
		}
	}
	return false;
}

auto contains_with_algorithm(std::vector<int> const & values, int const v) -> bool {
	auto const pos = std::find(std::begin(values), std::end(values), v);
	return pos != std::end(values);
}

auto contains_with_ranges(std::vector<int> const & values, int const v) -> bool {
	auto const pos = std::ranges::find(values, v);
	return pos != std::end(values);
}

auto execute_measurement(std::vector<int> const & values, std::ostream & out) -> void {
	out << std::boolalpha;

	auto const loop_start = std::chrono::high_resolution_clock::now();
	auto const loop_result = contains_with_loop(values, 2);
	auto const loop_end = std::chrono::high_resolution_clock::now();
	auto const loop_duration = std::chrono::duration_cast<std::chrono::milliseconds>(loop_end - loop_start);
	out << "found with a loop: " << loop_result << " in " << loop_duration.count() << "ms" << std::endl;

	auto const algorithm_start = std::chrono::high_resolution_clock::now();
	auto const algorithm_result = contains_with_algorithm(values, 2);
	auto const algorithm_end = std::chrono::high_resolution_clock::now();
	auto const algorithm_duration = std::chrono::duration_cast<std::chrono::milliseconds>(algorithm_end - algorithm_start);
	out << "found with an algorithm: " << algorithm_result << " in " << algorithm_duration.count() << "ms" << std::endl;

	auto const ranges_start = std::chrono::high_resolution_clock::now();
	auto const ranges_result = contains_with_ranges(values, 2);
	auto const ranges_end = std::chrono::high_resolution_clock::now();
	auto const ranges_duration = std::chrono::duration_cast<std::chrono::milliseconds>(ranges_end - ranges_start);
	out << "found with a range algorithm: " << ranges_result << " in " << ranges_duration.count() << "ms" << std::endl;
}

auto main() -> int {
	auto const values = std::vector(100000000, 1);
	for (auto i = 0; i < 10; i++) {
		execute_measurement(values, std::cout);
	}
}
