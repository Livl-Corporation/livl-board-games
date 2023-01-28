cmake_minimum_required(VERSION 3.24)
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

add_executable(Livl
        src/main.cpp
        src/controllers/GameController.cpp
        src/controllers/GameController.h
        src/models/Game.cpp
        src/models/Game.h
        src/models/interfaces/Player.h
        src/models/Position.h
        src/views/cli/ConsoleHandler.cpp
        src/models/Grid.h
        src/models/Grid.cpp
        src/views/gui/components/GridComponent.cpp
        src/views/gui/windows/game/GameWindow.cpp
        src/views/gui/windows/game/GameWindow.h
        src/views/gui/windows/game/GameWindow.ui
        src/views/gui/windows/menu/MenuWindow.h
        src/views/gui/windows/menu/MenuWindow.cpp
        src/views/gui/windows/menu/MenuWindow.ui
        src/models/interfaces/Token.h
        img/img.qrc
        src/models/MenuData.cpp
        src/models/MenuData.h
        src/controllers/MenuController.cpp
        src/controllers/MenuController.h
        src/models/enums/PlayMode.h
        src/models/enums/GameMode.h
        src/models/games/ticTacToe/TicTacToe.cpp
        src/models/games/ticTacToe/TicTacToe.h
        src/models/games/ticTacToe/players/TicTacToeHumanPlayer.cpp
        src/models/games/ticTacToe/players/TicTacToeHumanPlayer.h
        src/models/games/ticTacToe/players/TicTacToeComputerPlayer.cpp
        src/models/games/ticTacToe/players/TicTacToeComputerPlayer.h
        src/models/exceptions/UnimplementedPlayMode.h
        src/views/cli/menu/MenuConsole.h
        src/views/cli/menu/MenuConsole.cpp src/views/interfaces/MenuInteraction.h src/views/cli/game/GameConsole.cpp src/views/cli/game/GameConsole.h src/views/cli/game/GameConsole.h src/views/interfaces/GameView.h src/models/interfaces/Observable.h src/models/interfaces/Observable.h src/models/interfaces/Observer.h src/views/interfaces/GameInteraction.h src/views/interfaces/GameInteraction.h)

target_link_libraries(Livl
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(Livl PRIVATE src)
