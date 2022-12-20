cmake_minimum_required(VERSION 3.23)
project(poker)

set(CMAKE_CXX_STANDARD 14)

set(GAME
        game/AssesmentTable.h
        game/AssesmentTable.cpp
        game/Assessor.h
        game/Assessor.cpp
        game/card.h
        game/CardDeck.h
        game/CardDeck.cpp
        game/enum_hand.h
        game/enum_card.h
        game/Game.h
        game/Game.cpp
        )

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

add_library(gamelib.a game/Game.h ${GAME})
add_library(playerlib.a player/Player.h ${PLAYER})

target_include_directories(gamelib.a PRIVATE game)
target_include_directories(playerlib.a PRIVATE player)

file(COPY scoring.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(poker
        main.cpp
        PokerCLI.cpp
        PokerCLI.h
#        ${GAME}
#        ${PLAYER}
)
target_link_libraries(poker PRIVATE gamelib.a)
target_link_libraries(poker PRIVATE playerlib.a)
#target_include_directories(poker PRIVATE game player)


