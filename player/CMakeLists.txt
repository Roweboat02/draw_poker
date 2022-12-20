cmake_minimum_required(VERSION 3.23)
project(player)

set(CMAKE_CXX_STANDARD 14)


set (PLAYER
        player/card.h
        player/enum_hand.h
        player/enum_card.h
        player/Player.h
        player/Player.cpp
        player/PlayerBank.h
        player/PlayerBank.cpp
        player/PlayerHand.h
        player/PlayerHand.cpp
        )

add_executable(player
        main.cpp
        ${PLAYER}
)


