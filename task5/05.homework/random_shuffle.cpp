#include <iostream>

#include <algorithm> // std::shuffle
#include <chrono> 	 // std::chrono::system_clock
#include <random>	 // std::default_random_engine

#include <vector>

// Implement operator<< for the vector-class to print all elements
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) {
	for (auto iter = values.cbegin(); iter != values.cend(); ++iter) {
		if (iter != values.cbegin())
			os << ' ';
		os << *iter;
	}
	return os;
}

template<typename T>
void make_random_shuffle(std::vector<T>& values) {
	// 1. Take current time (count of seconds since `epoch begining`) as a seed
	auto seconds_count = std::chrono::system_clock::now().time_since_epoch().count();
	unsigned int seed = static_cast<unsigned int>(seconds_count);
	// 2. Initialize random engine
	std::default_random_engine engine{seed};
	// 3. Shuffle values
	std::shuffle(values.begin(), values.end(), engine);
}

int main() {

	std::vector<int> values{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "values before random shuffle:" << std::endl;
	std::cout << values << std::endl;

	make_random_shuffle(values);
	std::cout << "values after random shuffle:" << std::endl;
	std::cout << values << std::endl;

	make_random_shuffle(values);
	std::cout << "values after one more random shuffle:" << std::endl;
	std::cout << values << std::endl;

	return 0;
}