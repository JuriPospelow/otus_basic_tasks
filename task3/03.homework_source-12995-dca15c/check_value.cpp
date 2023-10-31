#include <iostream>
#include "random_value.hpp"
#include "high_scores.hpp"

using namespace std;

void help()
{
    cout << "Usage: check_value [-max X] [-table] [-level Y]" << endl;
    cout << "X max value for randow generator" << endl;
    cout << "Y = [1,2,3]" << endl;
}

int main(int argc, char** argv) {

unsigned max_value{100};

    if (argc >= 2) {
      std::string arg1_value{ argv[1] };
        if (arg1_value == "-max") {
            // We've detected the '-max' argument. And we extect that after this argument there is a value:
            if (argc < 3) {
                std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
                return -1;
            }
            // We need to parse the string to the int value
            max_value = std::stoi(argv[2]);
            //std::cout << "The '-parameter' value = " << parameter_value << std::endl;
        }
        else if (arg1_value == "-table") {
            read4file();
            return 0;
        }
        else if (arg1_value == "-test") {
            clean_file();
            return 0;
        }
        else if (arg1_value == "-level") {
           if (argc < 3) {
                std::cout << "Wrong usage! The argument '-level' requires some value!" << std::endl;
                return -1;
            }
            // We need to parse the string to the int value
            int level = std::stoi(argv[2]);
            switch(level){
                case 1:
                    max_value = 10;
                break;
                case 2:
                    max_value = 50;
                break;
                case 3:
                    max_value = 100;
                break;
                default:
                    return -1;
            }
        }
        else {
            help();
            return -1;
        }
    } else {
        help();
        return -1;
    }

    const unsigned int target_value = get_random_value(max_value);
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