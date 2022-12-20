//
// Created by noahr on 18/12/22.
//
#include <iostream>
#include "CardDeck.h"

int main(){
    Card vals0[20];
    Card vals1[5];
    CardDeck().draw(20,vals0);
    CardDeck().draw(5,vals1);

    char card_symbol[2];
    for (int i=0;i<5;i++){
        vals0[i].card_as_two_char(card_symbol);
        std::cout << i << std::endl;
        std::cout << "val0 symb" << std::endl;
        std::cout << card_symbol << std::endl;
        std::cout << "val0 suit/val" << std::endl;
        std::cout << vals0[i].suit << std::endl;
        std::cout << vals0[i].val << std::endl;

        vals1[i].card_as_two_char(card_symbol);
        std::cout << "val1 symb" << std::endl;
        std::cout << card_symbol << std::endl;

        std::cout << std::endl;
    }

    std::cout <<std::endl;

    for (int i=5;i<20;i++){
        vals0[i].card_as_two_char(card_symbol);
        std::cout << card_symbol << std::endl;
    }
}