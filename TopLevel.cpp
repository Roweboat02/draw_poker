//
// Created by noahr on 20/12/22.
//

#include "TopLevel.h"

void TopLevel::start() {
    player.bet();
    int bank_stats[2];
    player.bank_stats(bank_stats);
    game.first_deal(player.ptr_for_cards());

    bool fold_or_play = view.start(
            player.hand_as_str(),
            bank_stats[0],
            bank_stats[1]
            );

    state = DECISION0;
    decision(fold_or_play);
}

void TopLevel::decision(bool fold_or_play){
    if (!fold_or_play){
        state=FOLD;
        fold();
    } else {
        if (state==DECISION0){
            state=CARD_DECISION;
            return second_deal();
        } else if (state==DECISION1){
            state=ASSESS;
            return assess();
        }
    }
}

void TopLevel::second_deal() {
    view.request_held_cards_arr(player.ptr_for_held());
    int num_to_replace = player.num_cards_to_replace();

    Card new_cards[num_to_replace+1];
    new_cards[num_to_replace] = Card();

    game.second_deal(num_to_replace, new_cards);
    player.replace_non_held(new_cards);

    player.bet();
    int bank_stats[2];
    player.bank_stats(bank_stats);

    bool fold_or_play = view.receive_second_deal(
            player.hand_as_str(),
            bank_stats[0],
            bank_stats[1]
            );

    state=DECISION1;
    decision(fold_or_play);
}

void TopLevel::assess() {
    int winnings = game.assess(player.ptr_for_cards());
    int bank_stats[2];
    player.bank_stats(bank_stats);
    view.receive_assessment(winnings,
                            bank_stats[0],
                            bank_stats[1]);
    player.add_winnings(winnings);
}

void TopLevel::fold() {
    int winnings = 0;
    player.fold();
    int bank_stats[2];
    player.bank_stats(bank_stats);
    view.receive_assessment(winnings,
                            bank_stats[0],
                            bank_stats[1],
                            true);
    state=DEAL0;
}
