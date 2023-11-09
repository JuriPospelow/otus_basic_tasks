#include <chrono>
#include <iostream>
#include <vector>

#include <algorithm> // std::shuffle
#include <random>	 // std::default_random_engine

void fill_vector(std::vector<int> &values, size_t count) {
	values.resize(count);
	for (size_t i = 0; i < count; ++i) {
		values[i] = static_cast<int>(i);
	}
}

template <typename T>
void make_random_shuffle(std::vector<T> &values) {
	// 1. Take current time (count of seconds since `epoch begining`) as a seed
	auto seconds_count = std::chrono::system_clock::now().time_since_epoch().count();
	unsigned int seed = static_cast<unsigned int>(seconds_count);
	// 2. Initialize random engine
	std::default_random_engine engine{seed};
	// 3. Shuffle values
	std::shuffle(values.begin(), values.end(), engine);
}

void run_test_suite(size_t iteration_count) {
	const size_t elements_count = 100000;
	std::vector<int> values;
	// fill values with elements_count elements
	fill_vector(values, elements_count);
	// random shuffle values
	make_random_shuffle(values);


	std::cout << "iteration_count = " << iteration_count << std::endl;
	// std::sort algorithm measuring
	{
		// Take a start time
		auto start_time = std::chrono::system_clock::now();
		// Make a several iterations
		for (size_t i = 0; i < iteration_count; ++i) {
			std::vector<int> test_data = values;
			std::sort(test_data.begin(), test_data.end());
		}
		// Take an end time
		auto end_time = std::chrono::system_clock::now();
		// Calculate a duration
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
			end_time - start_time);
		std::cout << "std::sort duration = " << milliseconds.count() << "ms" << std::endl;
		std::cout << "std::sort avg = " << milliseconds.count() / iteration_count << "ms" << std::endl;
	}

	// C-style quick-sort algorithm measuring
	{
		// Take a start time
		auto start_time = std::chrono::system_clock::now();
		// Make a several iterations
		for (size_t i = 0; i < iteration_count; ++i) {
			std::vector<int> test_data = values;
			std::qsort(
				test_data.data(),
				test_data.size(),
				sizeof(int),
				[](const void *x, const void *y) {
					const int arg1 = *static_cast<const int *>(x);
					const int arg2 = *static_cast<const int *>(y);
					if (arg1 < arg2)
						return -1;
					if (arg1 > arg2)
						return 1;
					return 0;
				});
		}
		// Take an end time
		auto end_time = std::chrono::system_clock::now();
		// Calculate a duration
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
			end_time - start_time);
		std::cout << "qsort duration = " << milliseconds.count() << "ms" << std::endl;
		std::cout << "qsort avg = " << milliseconds.count() / iteration_count << "ms" << std::endl;
	}
}

int main() {

	run_test_suite(1);
	std::cout << std::endl;

	run_test_suite(10);
	std::cout << std::endl;

	run_test_suite(100);
	std::cout << std::endl;

	return 0;
}
