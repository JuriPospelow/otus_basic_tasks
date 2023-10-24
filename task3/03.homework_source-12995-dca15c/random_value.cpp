#include <iostream>

#include <cstdlib>
#include <ctime>

int get_random_value(unsigned max_value_) {

    const int max_value = max_value_;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    const int random_value = std::rand() % max_value;

    // std::cout << "random_value: " << random_value << " max_value: " << max_value << std::endl;

    return random_value;
}