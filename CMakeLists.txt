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
        view/View.cpp view/View.h)

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

set (VIEW
        ./view/CardButton.h
        ./view/CardButton.cpp
        ./view/PointBoard.h
        ./view/PointBoard.cpp
        ./view/View.cpp
        ./view/View.h
        )

add_library(gamelib game/Game.h ${GAME})
add_library(playerlib player/Player.h ${PLAYER})
add_library(viewlib view/View.h ${VIEW})

target_include_directories(gamelib PRIVATE game)
target_include_directories(playerlib PRIVATE player)
target_include_directories(viewlib PRIVATE view)

file(COPY scoring.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(poker
        TopLevel.cpp TopLevel.h
        )

target_link_libraries(poker PRIVATE gamelib)
target_link_libraries(poker PRIVATE playerlib)
target_link_libraries(poker PRIVATE viewlib)
#target_include_directories(poker PRIVATE game player)


