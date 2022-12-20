//
// Created by noahr on 18/12/22.
//

#include <iostream>
#include "enum_card.h"

#ifndef POKER_CARD_H
#define POKER_CARD_H




struct Card {

    Card(int card_value, int card_suit){
        val=card_value;
        suit=card_suit;
    };

    Card(){val=0;suit=0;};

    int to_int() const{return suit*14+val;}


    // suit*14+value(2,...,14)
    static Card from_int(int card_num){return {card_num%14,card_num/14};}

    std::string card_as_str() const{ return suit_to_string()+val_to_char();};

    int val;
    int suit;

    private:
        std::string suit_to_string() const {
            switch (suit) {
                case (DIAMONDS):
                    return "\u2666";
                case (CLUBS):
                    return "\u2663";
                case (SPADES):
                    return "\u2660";
                case (HEARTS):
                    return "\u2665";
                default:
                    std::cout<<suit;
                    return "#";
            }
        }

        char val_to_char() const {
            switch (val) {
                case (TWO):
                    return '2';
                case (THREE):
                    return '3';
                case (FOUR):
                    return '4';
                case (FIVE):
                    return '5';
                case (SIX):
                    return '6';
                case (SEVEN):
                    return '7';
                case (EIGHT):
                    return '8';
                case (NINE):
                    return '9';
                case (TEN):
                    return '0';
                case (JACK):
                    return 'J';
                case (QUEEN):
                    return 'Q';
                case (KING):
                    return 'K';
                case (ACE):
                    return 'A';
                default:
                    std::cout<<val;
                    return '#';

            }
        }

};

#endif //POKER_CARD_H