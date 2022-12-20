//
// Created by noahr on 19/12/22.
//

#ifndef POKER_ASSESMENTTABLE_H
#define POKER_ASSESMENTTABLE_H


#include "card.h"
#include "enum_hand.h"

class AssesmentTable {
private:
    const char *filename = "./scoring.txt";
    int scores[10];
    int* read_scoring();
public:

    AssesmentTable(){}
    int assess(int hand_value);
};


#endif //POKER_ASSESMENTTABLE_H
