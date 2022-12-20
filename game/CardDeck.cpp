//
// Created by noahr on 18/12/22.
//


#include "CardDeck.h"

CardDeck::CardDeck() {
    for (bool & spent_card : spent_cards){
        spent_card = false;
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

        if (!spent_cards[future_card]){
            spent_cards[future_card] = true;
            return {val, suit};
        }
    }
}

void CardDeck::draw(int n, Card out[]) {
    for (int i=0; i<n; i++){
        out[i] = random_card();
    }
}




