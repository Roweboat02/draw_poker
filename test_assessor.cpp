//
// Created by noahr on 18/12/22.
//
#include <iostream>
#include "Assessor.h"

bool test_four_of_a_kind(){
    Card arr[6] = {
            Card(ACE, SPADES),
            Card(ACE, HEARTS),
            Card(ACE, CLUBS),
            Card(ACE, DIAMONDS),
            Card(TWO, DIAMONDS),
            Card()
    };
    Assessor ass = Assessor(arr);

    return (ass.hand_value == FOUR_OF_A_KIND);
}

bool test_is_flush(){
    Card arrf[6] = {
            Card(ACE, SPADES),
            Card(SIX, HEARTS),
            Card(THREE, CLUBS),
            Card(FOUR, DIAMONDS),
            Card(FIVE, DIAMONDS),
            Card()
    };
    Card arrt[6] = {
            Card(ACE, SPADES),
            Card(SIX, SPADES),
            Card(THREE, SPADES),
            Card(FOUR, SPADES),
            Card(FIVE, SPADES),
            Card()
    };
    bool a = Assessor(arrf).hand_value!=FLUSH;
    bool b = Assessor(arrt).hand_value==FLUSH;

    return a&&b;
}

bool test_is_straight(){
    Card arrf[6] = {
            Card(TWO, SPADES),
            Card(SEVEN, HEARTS),
            Card(THREE, CLUBS),
            Card(FOUR, DIAMONDS),
            Card(FIVE, DIAMONDS),
            Card()
    };
    Card arrt[6] = {
            Card(TWO, SPADES),
            Card(THREE, DIAMONDS),
            Card(FOUR, CLUBS),
            Card(FIVE, HEARTS),
            Card(SIX, SPADES),
            Card()
    };
    bool a = Assessor(arrf).hand_value!=STRAIGHT;
    bool b = Assessor(arrt).hand_value==STRAIGHT;

    return a&&b;
}

bool test_is_straight_flush_and_royal_flush(){
    Card arr_sf[6] = {
            Card(TWO, SPADES),
            Card(THREE, SPADES),
            Card(FOUR, SPADES),
            Card(FIVE, SPADES),
            Card(SIX, SPADES),
            Card()
    };
    Card arr_rf[6] = {
            Card(TEN, SPADES),
            Card(JACK, SPADES),
            Card(QUEEN, SPADES),
            Card(KING, SPADES),
            Card(ACE, SPADES),
            Card()
    };
    bool a = Assessor(arr_sf).hand_value==STRAIGHT_FLUSH;
    bool b = Assessor(arr_rf).hand_value==ROYAL_FLUSH;

    return a&&b;
}

bool test_full_house_and_two_pair(){
    Card arr_fh[6] = {
            Card(TWO, SPADES),
            Card(TWO, HEARTS),
            Card(THREE, CLUBS),
            Card(THREE, DIAMONDS),
            Card(THREE, DIAMONDS),
            Card()
    };
    Card arr_tp[6] = {
            Card(TWO, SPADES),
            Card(TWO, HEARTS),
            Card(THREE, DIAMONDS),
            Card(THREE, HEARTS),
            Card(SIX, SPADES),
            Card()
    };
    bool a = Assessor(arr_fh).hand_value==FULL_HOUSE;
    bool b = Assessor(arr_tp).hand_value==TWO_PAIR;

    return a&&b;
}

int main(){
    std::cout << "4 of kind";
    std::cout << std::endl;
    std::cout << test_four_of_a_kind();
    std::cout << std::endl;

    std::cout << "flush";
    std::cout << std::endl;
    std::cout << test_is_flush();
    std::cout << std::endl;

    std::cout << "straight";
    std::cout << std::endl;
    std::cout << test_is_straight();
    std::cout << std::endl;

    std::cout << "straight flush and royal flush";
    std::cout << std::endl;
    std::cout << test_is_straight_flush_and_royal_flush();
    std::cout << std::endl;

    std::cout << "full house and 2 pair";
    std::cout << std::endl;
    std::cout << test_full_house_and_two_pair();
    std::cout << std::endl;
}
