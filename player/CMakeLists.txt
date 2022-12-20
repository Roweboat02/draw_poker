cmake_minimum_required(VERSION 3.23)
project(player)

set(CMAKE_CXX_STANDARD 14)


set (PLAYER
        card.h
        enum_hand.h
        enum_card.h
        Player.h
        Player.cpp
        PlayerBank.h
        PlayerBank.cpp
        PlayerHand.h
        PlayerHand.cpp
        )

add_executable(player
        player_main.cpp
        ${PLAYER}
)


