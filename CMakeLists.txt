cmake_minimum_required(VERSION 3.16)

project(tp-cpp)

add_executable(boardgame
        src/main.cpp
        src/interfaces/game.cpp
        src/interfaces/grid.cpp
        src/models/player.cpp
        src/shared/shared.cpp
        src/shared/consoleHandler.cpp
        src/shared/evaluators/linearGameEvaluator.cpp
        src/games/power4/power4.cpp
        src/games/power4/power4PositionRequester.cpp
        src/games/power4/power4Grid.cpp
        src/games/tictactoe/tictactoePositionRequester.cpp
        src/games/tictactoe/tictactoe.cpp
        src/games/gameFactory.cpp
        src/games/othello/othello.cpp
        src/games/othello/othelloPositionRequester.cpp
        src/games/othello/othelloGameEvaluator.cpp
        )

add_executable(tp1-ex1
        archives/TP1-ex1/main.cpp
        archives/TP1-ex1/functions.cpp
)

add_executable(tp1-tenis
        archives/TP1-tenis/main.cpp
)

add_executable(tp1-ex3
        archives/TP1-ex3/main.cpp
        archives/TP1-ex3/functions.cpp
)

add_executable(tp1-ex3_2
        archives/TP1-ex3_2/main.cpp
)

add_executable(tp2
        archives/TP2/main.cpp
        archives/TP2/rectangle.cpp
        archives/TP2/round.cpp
        archives/TP2/triangle.cpp
        archives/TP2/functions.cpp
)

