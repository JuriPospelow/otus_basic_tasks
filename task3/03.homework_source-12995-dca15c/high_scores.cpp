#include <iostream>
#include <fstream>
#include <string>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

std::string user_name;
const std::string high_scores_filename = "high_scores.txt";
unsigned attempts_count{};

void ask_name()
{
    // Ask about name
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> user_name;
}

void put_attempts_count(unsigned attempts_cnt)
{
    attempts_count = attempts_cnt;
}

int clean_file()
{
    typedef multimap<string, int> MultiMap;
    MultiMap multimap_high_score;
    std::fstream file{high_scores_filename};
    if (!file.is_open()) {
       std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
       return -1;
    }
    // std::cout << "High scores table:" << std::endl;
    std::string username;
    int high_score = 0;
    while (true) {
        // Read the username first
        file >> username;
        // Read the high score next
        file >> high_score;
        // Ignore the end of line symbol
        file.ignore();

        if (file.fail()) {
            break;
        }
        multimap_high_score.insert(pair<string, int>(username, high_score));
    }
    // printing multimap multimap_high_score
    MultiMap::iterator itr;
    // cout << "\tUser Name\tHIGH SCORE\n";

    vector<string> v_moreThanOne;
    string tmp{};

    for (itr = multimap_high_score.begin(); itr != multimap_high_score.end(); ++itr) {
        if(multimap_high_score.count(itr->first) == 1) {
            file << itr->first << " " << itr->second
                << '\n';
        } else {
            if (tmp != itr->first) v_moreThanOne.push_back(itr->first);
            tmp = itr->first;
      }
    }
    pair <MultiMap::iterator, MultiMap::iterator> ret;
    int tmp_value{numeric_limits<int>::max()};
    for (vector<string>::iterator itr = v_moreThanOne.begin(); itr != v_moreThanOne.end(); ++itr) {
         file << *itr << " ";
        ret = multimap_high_score.equal_range(*itr);
        for (MultiMap::iterator it=ret.first; it!=ret.second; ++it) {
            tmp_value = it->second < tmp_value ? it->second : tmp_value;
        }
        file << tmp_value << endl;
        tmp_value = numeric_limits<int>::max();
    }

    return 0;
    // cout << endl;
}

    // Write new high score to the records table
int write2file()
{
    // We should open the output file in the append mode - we don't want
    // to erase previous results.
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    // Append new results to the table:
    out_file << user_name << ' ';
    out_file << attempts_count;
    out_file << std::endl;

    out_file.close();

    clean_file();

    return 0;
} // end of score here just to mark end of the logic block of code

// Read the high score file and print all results
int read4file()
{
    typedef multimap<string, int> MultiMap;
    MultiMap multimap_high_score;
    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
       std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
       return -1;
    }
    std::cout << "High scores table:" << std::endl;
    std::string username;
    int high_score = 0;
    while (true) {
        // Read the username first
        in_file >> username;
        // Read the high score next
        in_file >> high_score;
        // Ignore the end of line symbol
        in_file.ignore();

        if (in_file.fail()) {
            break;
        }
        multimap_high_score.insert(pair<string, int>(username, high_score));
        // Print the information to the screen
        // std::cout << username << '\t' << high_score << std::endl;
    }
    // printing multimap multimap_high_score
    MultiMap::iterator itr;
    cout << "\tUser Name\tHIGH SCORE\n";

    vector<string> v_moreThanOne;
    string tmp{};

    for (itr = multimap_high_score.begin(); itr != multimap_high_score.end(); ++itr) {
        if(multimap_high_score.count(itr->first) == 1) {
            cout << '\t' << itr->first << "\t\t" << itr->second
                << '\n';
        } else {
            if (tmp != itr->first) v_moreThanOne.push_back(itr->first);
            tmp = itr->first;
      }
    }
    pair <MultiMap::iterator, MultiMap::iterator> ret;
    int tmp_value{numeric_limits<int>::max()};
    for (vector<string>::iterator itr = v_moreThanOne.begin(); itr != v_moreThanOne.end(); ++itr) {
         cout << '\t' << *itr << "\t\t";
        ret = multimap_high_score.equal_range(*itr);
        for (MultiMap::iterator it=ret.first; it!=ret.second; ++it) {
            tmp_value = it->second < tmp_value ? it->second : tmp_value;
        }
        cout << tmp_value << endl;
        tmp_value = numeric_limits<int>::max();
    }


    cout << endl;

    return 0;
}
