#include <iostream>
#include "random_value.hpp"
#include "high_scores.hpp"

int main() {

    const unsigned int target_value = get_random_value();
    unsigned int current_value = 0;
    bool not_win = true;

    ask_name();

    std::cout << "Enter your guess:" << std::endl;

    unsigned attempts_cnt{};
    do {
        std::cin >> current_value;
        if (std::cin.fail()) {
            std::cout << "Bad value!" << std::endl;
            return -1;
        }

        if (current_value < target_value) {
            std::cout << "greater than " << current_value << std::endl;
            ++attempts_cnt;
        }
        else if (current_value > target_value) {
            std::cout << "less than " << current_value << std::endl;
            ++attempts_cnt;
        }
        else {
            std::cout << "you win! attempts = " << attempts_cnt << std::endl;
            break;
        }

    } while(true);

    put_attempts_count(attempts_cnt);
    write2file();
    read4file();



    return 0;
}