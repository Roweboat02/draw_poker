//
// Created by noahr on 18/12/22.
//

#include <iostream>

#ifndef POKER_CARD_H
#define POKER_CARD_H

#endif //POKER_CARD_H

enum suit{DIAMONDS, CLUBS, HEARTS, SPADES};
enum value{TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13, ACE=14};

struct Card {

    Card(int card_value, int card_suit){
        val=card_value;
        suit=card_suit;
    };

    Card(){val=0;suit=0;};

    int to_int() const{return suit*14+val;}


    // suit*14+value(2,...,14)
    static Card from_int(int card_num){return {card_num%14,card_num/14};}

    void card_as_two_char(char out[]) const{ out[0]=suit_to_char();out[1]=val_to_char();};

    int val;
    int suit;

    private:
        char suit_to_char() const {
            switch (suit) {
                case (DIAMONDS):
                    return 'D';
                case (CLUBS):
                    return 'C';
                case (SPADES):
                    return 'S';
                case (HEARTS):
                    return 'H';
                default:
                    std::cout<<suit;
                    return '#';
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
