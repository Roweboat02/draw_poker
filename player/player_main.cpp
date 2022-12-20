//
// Created by noahr on 19/12/22.
//

#include "PlayerHand.h"

bool test_add_rmv_holding(){
    bool correct = true;
    PlayerHand ph = PlayerHand();
    Card* hand_ptr = ph.hand;
    *hand_ptr = Card(ACE, SPADES),
    hand_ptr++;
    *hand_ptr = Card(TWO, SPADES),
    hand_ptr++;
    *hand_ptr = Card(THREE, HEARTS),
    hand_ptr++;
    *hand_ptr = Card(FOUR, DIAMONDS),
    hand_ptr++;
    *hand_ptr = Card(FIVE, CLUBS),
    hand_ptr++;
    *hand_ptr = Card();


    for (int i=0; i<6; i++){
        correct=correct && (ph.holding[i].val==0);
    }
    ph.add_to_holding(0);
    ph.add_to_holding(4);
    for (int i=0; i<6; i++){
        if (i==0 || i==4){
            correct=correct&&ph.holding[i].val!=0;
        } else {
            correct=correct&&ph.holding[i].val==0;
        }

    }
    ph.remove_from_holding(0);
    for (int i=0; i<6; i++){
        if (i==4){
            correct=correct&&ph.holding[i].val!=0;
        } else {
            correct=correct&&ph.holding[i].val==0;
        }

    }
    return correct;
}
bool test_holding_count(){
    bool correct = true;
    Card hand[6] = {
            Card(ACE, SPADES),
            Card(TWO, SPADES),
            Card(THREE, HEARTS),
            Card(FOUR, DIAMONDS),
            Card(FIVE, CLUBS),
            Card(),
    };
    PlayerHand ph = PlayerHand(hand);

    correct= correct && (ph.number_of_held()==0);
    ph.add_to_holding(0);
    ph.add_to_holding(4);

    correct= correct && (ph.number_of_held()==2);

    ph.remove_from_holding(0);

    correct= correct && (ph.number_of_held()==1);

    return correct;
}

bool test_replace_non_held(){
    bool correct = true;
    Card hand[6] = {
            Card(ACE, SPADES),
            Card(TWO, SPADES),
            Card(THREE, CLUBS),
            Card(FOUR, CLUBS),
            Card(FIVE, CLUBS),
            Card(),
    };
    PlayerHand ph = PlayerHand(hand);

    correct= correct && (ph.number_of_held()==0);
    ph.add_to_holding(1);
    ph.add_to_holding(2);
    ph.add_to_holding(3);

    Card new_cards[3]={
            Card(ACE, HEARTS),
            Card(ACE, DIAMONDS),
            Card(),
    };
    ph.replace_non_held(new_cards);

    Card answer[6]={
            Card(ACE, HEARTS),
            Card(TWO, SPADES),
            Card(THREE, CLUBS),
            Card(FOUR, CLUBS),
            Card(ACE, DIAMONDS),
            Card(),
    };

    for (int i = 0; i < 5; ++i) {
        correct= correct && (answer[i].val==ph.hand[i].val);
        correct= correct && (answer[i].suit==ph.hand[i].suit);
    }

    return correct;
}

int main(){
    std::cout << "remove and add from holding";
    std::cout << std::endl;
    std::cout << test_add_rmv_holding();
    std::cout << std::endl;

    std::cout << "holding count";
    std::cout << std::endl;
    std::cout << test_holding_count();
    std::cout << std::endl;

    std::cout << "replace non held";
    std::cout << std::endl;
    std::cout << test_replace_non_held();
    std::cout << std::endl;

}