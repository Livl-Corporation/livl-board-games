cmake_minimum_required(VERSION 3.5)

project(Livl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(Qt6 COMPONENTS Core Gui Widgets)

add_executable(Livl
        src/interfaces/game.cpp
        src/interfaces/grid.cpp
        src/models/player.cpp
        src/shared/shared.cpp
        src/cli/consoleHandler.cpp
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
        src/gui/forms/menu/menu.cpp
        src/gui/forms/menu/menu.ui
        src/gui/forms/game/gamewindow.cpp
        src/gui/forms/game/gamewindow.ui
        img/img.qrc
        src/gui/components/gridcomponent.cpp
        src/gui/components/gridcomponent.ui
        src/cli/gameConsoleInteractions.cpp
        src/gui/gameGuiInteractions.cpp
        src/cli/menuConsoleInterface.cpp
        src/main.cpp
        src/gui/menuGuiInteractions.cpp
        src/shared/exceptions/column-full-exception.hpp
        src/shared/interactionsProvider.h
        )

target_include_directories(Livl PRIVATE src)

target_link_libraries(Livl
        Qt::Core
        Qt::Gui
        Qt::Widgets)


if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
