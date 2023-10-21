#include <iostream>

#include <cstdlib>
#include <ctime>

int get_random_value() {

    const int max_value = 100;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    const int random_value = std::rand() % 100;

    std::cout << random_value << std::endl;

    return random_value;
}