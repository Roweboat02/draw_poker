//
// Created by noahr on 18/12/22.
//
#include <iostream>
#include "Assessor.h"

bool test_four_of_a_kind(){
    Card arr[5] = {
            Card(ACE, SPADES),
            Card(ACE, HEARTS),
            Card(ACE, CLUBS),
            Card(ACE, DIAMONDS),
            Card(TWO, DIAMONDS)
    };
    Assessor ass = Assessor(arr);

    return (ass.hand_value == FOUR_OF_A_KIND);
}

bool test_is_flush(){
    Card arrf[5] = {
            Card(ACE, SPADES),
            Card(SIX, HEARTS),
            Card(THREE, CLUBS),
            Card(FOUR, DIAMONDS),
            Card(FIVE, DIAMONDS)
    };
    Card arrt[5] = {
            Card(ACE, SPADES),
            Card(SIX, SPADES),
            Card(THREE, SPADES),
            Card(FOUR, SPADES),
            Card(FIVE, SPADES)
    };
    bool a = Assessor(arrf).hand_value!=FLUSH;
    bool b = Assessor(arrt).hand_value==FLUSH;

    return a&&b;
}

bool test_is_straight(){
    Card arrf[5] = {
            Card(TWO, SPADES),
            Card(SEVEN, HEARTS),
            Card(THREE, CLUBS),
            Card(FOUR, DIAMONDS),
            Card(FIVE, DIAMONDS)
    };
    Card arrt[5] = {
            Card(TWO, SPADES),
            Card(THREE, DIAMONDS),
            Card(FOUR, CLUBS),
            Card(FIVE, HEARTS),
            Card(SIX, SPADES)
    };
    bool a = Assessor(arrf).hand_value!=STRAIGHT;
    bool b = Assessor(arrt).hand_value==STRAIGHT;

    return a&&b;
}

bool test_is_straight_flush_and_royal_flush(){
    Card arr_sf[5] = {
            Card(TWO, SPADES),
            Card(THREE, SPADES),
            Card(FOUR, SPADES),
            Card(FIVE, SPADES),
            Card(SIX, SPADES)
    };
    Card arr_rf[5] = {
            Card(TEN, SPADES),
            Card(JACK, SPADES),
            Card(QUEEN, SPADES),
            Card(KING, SPADES),
            Card(ACE, SPADES)
    };
    bool a = Assessor(arr_sf).hand_value==STRAIGHT_FLUSH;
    bool b = Assessor(arr_rf).hand_value==ROYAL_FLUSH;

    return a&&b;
}

bool test_full_house_and_two_pair(){
    Card arr_fh[5] = {
            Card(TWO, SPADES),
            Card(TWO, HEARTS),
            Card(THREE, CLUBS),
            Card(THREE, DIAMONDS),
            Card(THREE, DIAMONDS)
    };
    Card arr_tp[5] = {
            Card(TWO, SPADES),
            Card(TWO, HEARTS),
            Card(THREE, DIAMONDS),
            Card(THREE, HEARTS),
            Card(SIX, SPADES)
    };
    bool a = Assessor(arr_fh).hand_value==FULL_HOUSE;
    bool b = Assessor(arr_tp).hand_value==TWO_PAIR;

    return a&&b;
}

int main(){
    std::cout << (
            test_four_of_a_kind()
            && test_is_flush()
            && test_is_straight()
            && test_is_straight_flush_and_royal_flush()
            && test_full_house_and_two_pair());
}
