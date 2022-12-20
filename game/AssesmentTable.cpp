//
// Created by noahr on 19/12/22.
//

#include "AssesmentTable.h"

int AssesmentTable::assess(int hand_value) {
    switch(hand_value){
        case HIGH_CARD:
            return scores[0];

        case PAIR:
            return scores[1];

        case TWO_PAIR:
            return scores[2];

        case THREE_OF_A_KIND:
            return scores[3];

        case STRAIGHT:
            return scores[4];

        case FLUSH:
            return scores[5];

        case FULL_HOUSE:
            return scores[6];

        case FOUR_OF_A_KIND:
            return scores[7];

        case STRAIGHT_FLUSH:
            return scores[8];

        case ROYAL_FLUSH:
            return scores[9];
        default:
            return 0;
    }
}

void AssesmentTable::read_scoring() {
    score_file.open(filename, std::ios::in);
    int* score_ptr = scores;

    while(score_ptr!=&scores[10]){
        *score_ptr = read_scoring_line();
        score_ptr++;
    }
}

int AssesmentTable::read_scoring_line() {
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





// # HIGH_CARD:
// 0;
// # PAIR:
// 5;
// # TWO_PAIR:
// 10;
// # THREE_OF_A_KIND:
// 15;
// # STRAIGHT:
// 20;
// # FLUSH:
// 25;
// break;
// # FULL_HOUSE:
// 40;
// break;
// # FOUR_OF_A_KIND:
// 50;
// break;
// # STRAIGHT_FLUSH:
// 75;
// # ROYAL_FLUSH:
// 100;
