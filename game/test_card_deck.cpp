//
// Created by noahr on 18/12/22.
//
#include <iostream>
#include "CardDeck.h"

bool draw_52(){
    CardDeck cd = CardDeck();
    Card full_deck[53];
    full_deck[52] = Card();
    cd.draw(52, full_deck);

    bool correct = true;

    for (int i = 0; i < 51; ++i) {
        for (int j = i+1; j < 52; ++j) {
            correct = correct &&
                    !(full_deck[i].val==full_deck[j].val && full_deck[i].suit==full_deck[j].suit);
            cd.spent_cards;
        }
    }
    return correct;
}

bool generic_test(){
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

int main(){
    std::cout << draw_52();
}