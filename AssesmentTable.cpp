//
// Created by noahr on 19/12/22.
//

#include <fstream>
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
    }
}

int *AssesmentTable::read_scoring() {
    std::fstream score_file;
    score_file.open(filename, std::ios::in);

    char ch;
    char possible_nums[3];

    char* possible_num = possible_nums;
    int* score_ptr = scores;

    while(score_ptr!=&scores[9]){
        score_file >> ch;
        if (ch=='#'){
            while (ch!='\n'){
                *possible_num=ch;
                score_file>>ch;
            }}
        else {
            while (ch!='\n'){
                *possible_num=ch;
                possible_num++;
                score_file>>ch;
            }
            *score_ptr= std::stoi(possible_nums);
            score_ptr++;
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
