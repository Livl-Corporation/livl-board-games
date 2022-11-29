cmake_minimum_required(VERSION 3.16)

project(tp-cpp)

add_executable(tp1-ex1
    src/TP1-ex1/main.cpp
    src/TP1-ex1/functions.cpp
)

add_executable(tp1-tenis
    src/TP1-tenis/main.cpp
)

add_executable(tp1-ex3
    src/TP1-ex3/main.cpp
    src/TP1-ex3/functions.cpp
)

add_executable(tp1-ex3_2
    src/TP1-ex3_2/main.cpp
)

add_executable(tp2
    src/TP2/main.cpp
    src/TP2/rectangle.cpp
    src/TP2/round.cpp
    src/TP2/triangle.cpp
    src/TP2/functions.cpp
)

add_executable(tp3
    src/TP3/main.cpp
    src/TP3/game.cpp
    src/TP3/grid.cpp
    src/TP3/shared/functions.cpp
    src/TP3/games/power4.cpp
)