//
// Created by noahr on 20/12/22.
//

#ifndef POKER_CARDBUTTON_H
#define POKER_CARDBUTTON_H


#include <string>
#include <utility>

class CardButton {
    std::string face_val;

    void toggle_held(){held= !held;}

public:
    void set(std::string text){face_val=std::move(text);}

    bool held=false;
};


#endif //POKER_CARDBUTTON_H
