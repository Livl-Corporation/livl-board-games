//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_MENUCONTROLLER_H
#define LIVL_MENUCONTROLLER_H


#include <utility>
#include <memory>
#include <filesystem>
#include <fstream>

#include "models/Game.h"
#include "GameController.h"
#include "models/enums/PlayMode.h"
#include "models/enums/GameMode.h"
#include "models/games/ticTacToe/TicTacToe.h"
#include "views/gui/windows/game/GameWindow.h"
#include "models/games/connectFour/ConnectFour.h"
#include "models/games/othello/Othello.h"
#include "models/games/checkers/Checkers.h"

class MenuController {

public:
    MenuController() = default;

    void onGameChoose(GameMode gameSelection, PlayMode playerSelection, const std::shared_ptr<GameView>& gameView);

protected:
    static std::shared_ptr<Game> createGame(GameMode gameMode, PlayMode playerSelection);

};

#endif //LIVL_MENUCONTROLLER_H