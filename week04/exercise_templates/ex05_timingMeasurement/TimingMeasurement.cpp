#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

constexpr std::size_t testSize{1000000};

using TestData = std::vector<std::string>;

auto RandomIndex() -> std::size_t {
  static std::random_device
      rd{}; // Will be used to obtain a seed for the random number engine
  static std::mt19937 gen{
      rd()}; // Standard mersenne_twister_engine seeded with rd()
  static std::uniform_int_distribution<size_t> dis{0, testSize - 1};
  return dis(gen);
}

auto passByValue(TestData data) -> std::string {
  std::size_t index = RandomIndex();
  return data[index];
}

auto copyInAndOut() -> void {
  TestData v(testSize, " ");
  for (int i = 0; i < 100; i++) {
    auto res = passByValue(v);
  }
}

auto measureExecutionTime(std::function<auto()->void>f) -> std::chrono::microseconds {
  using namespace std::chrono;
  high_resolution_clock clock{};
  auto start = clock.now();
  f();
  auto end = clock.now();
  return duration_cast<microseconds>(end - start);
}
auto main() -> int {
  auto elapsed = measureExecutionTime(copyInAndOut).count();
  std::cout << "source_outside: " << elapsed << " us\n";
}
