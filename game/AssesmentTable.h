//
// Created by noahr on 19/12/22.
//

#ifndef POKER_ASSESMENTTABLE_H
#define POKER_ASSESMENTTABLE_H


#include <fstream>
#include <climits>
#include <csignal>
#include "card.h"
#include "enum_hand.h"

class AssesmentTable {
private:
public:
    const char *filename = "scoring.txt";
    std::fstream score_file;
    int scores[10];
    void read_scoring();
    int read_scoring_line();

    AssesmentTable(){
        char buffer[PATH_MAX];
        std::cout<<"ME_SA"<<std::endl;
        std::cout<< getcwd(buffer, sizeof(buffer))<<std::endl;
        read_scoring();
    }
    int assess(int hand_value);
};


#endif //POKER_ASSESMENTTABLE_H
