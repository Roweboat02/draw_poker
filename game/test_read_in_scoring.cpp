//
// Created by noahr on 20/12/22.
//

#include <unistd.h>
#include <cstdio>
#include <limits.h>
#include "AssesmentTable.h"

int read_scoring_line() {
    std::fstream score_file ("scoring.txt");

    while (score_file.is_open()) {

        char chrs[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        char* chr_ptr = chrs;

        score_file >> chrs;

        if (chrs[0]=='#'){ continue;}
        else {
            char str[4] = "\0\0\0";
            char* st = str;
            while(*chr_ptr!='\0'){
                *st = *chr_ptr;
                chr_ptr++;
                st++;
            }

            return std::stoi(str);
        }
    }
}

int main(){
//    char buffer[PATH_MAX];
//    std::cout<<"ME_SA"<<std::endl;
//    std::cout<< getcwd(buffer, sizeof(buffer));
    AssesmentTable ass = AssesmentTable();
    for (int i = 0; i < 10; ++i) {
        std::cout << ass.scores[i]<<std::endl;
    }
}