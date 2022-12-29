cmake_minimum_required(VERSION 3.5)

project(Livl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
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
        src/forms/main.cpp
        src/forms/menu.cpp
        src/forms/menu.h
        src/forms/menu.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Livl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Livl APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Livl SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Livl
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Livl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Livl PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Livl)
endif()
