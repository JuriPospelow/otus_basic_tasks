#ifndef HIGH_SCORE_HPP
#define HIGH_SCORE_HPP

void ask_name();
void put_attempts_count(unsigned attempts_cnt = 0);
// Write new high score to the records table
void write2file();
// Read the high score file and print all results
void read4file();

int clean_file();

#endif
