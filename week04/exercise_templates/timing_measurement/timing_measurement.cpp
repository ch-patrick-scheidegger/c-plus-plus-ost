#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <random>


constexpr size_t testsize{1000000};

using testdata=std::vector<std::string>;
size_t random_index(){
    static std::random_device rd{};  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen{rd()}; //Standard mersenne_twister_engine seeded with rd()
    static std::uniform_int_distribution<size_t> dis{0, testsize-1};
    return dis(gen);
}

std::string pass_by_value(testdata v){
	size_t index = random_index();
	return v[index];
}
void copying_source_outside(){
	testdata v(testsize," ");
	for (int i = 0; i < 100; i++)
	{
		auto res = pass_by_value(v);
	}
}

std::chrono::microseconds time_func(void  (f)()){
	using namespace std::chrono;
	high_resolution_clock clock { };
	auto start=clock.now();
		f();
	auto end = clock.now();
	return duration_cast<microseconds>(end - start);
}
int main(){
	auto elapsed = time_func(copying_source_outside).count();
	std::cout << "source_outside :" << elapsed << " us\n";
}
