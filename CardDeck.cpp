//
// Created by noahr on 18/12/22.
//

#include <cstdlib>
#include <ctime>

#include "CardDeck.h"

CardDeck::CardDeck() {
    for (int i=0; i<15; i++){
        spent_cards[i] = 0;
    }
}

int CardDeck::rand_num(int low, int high) {
    static bool first_time = true;
    static std::default_random_engine gen;
    if (first_time){
        std::random_device rd;
        gen.seed(rd());
        first_time= false;
    }
    std::uniform_int_distribution<int> distribution(low,high-1);

    return distribution(gen);
}

int CardDeck::random_suit() {
    return rand_num(0,4);
}

int CardDeck::random_val() {
    return rand_num(2,15);
}

Card CardDeck::random_card() {
    while (true){
        int suit = random_suit();
        int val = random_val();
        int future_card = suit*14 + val;
        for (int & spent_card : spent_cards){
            if (spent_card==future_card){break;}
            else {return {val, suit};}
        }
    }
}

void CardDeck::draw(int n, Card out[]) {
    for (int i=0; i<n; i++){
        out[i] = random_card();
    }
}




