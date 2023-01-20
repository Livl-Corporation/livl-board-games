//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_MENUCONTROLLER_H
#define LIVL_MENUCONTROLLER_H


#include <utility>
#include <memory>

#include "models/Game.h"
#include "GameController.h"
#include "models/enums/PlayMode.h"
#include "models/enums/GameMode.h"
#include "models/games/ticTacToe/TicTacToe.h"
#include "views/gui/windows/game/GameWindow.h"

class MenuController {

public:
    MenuController() = default;

    void onPlayClicked(GameMode gameSelection, PlayMode playerSelection);

protected:

    static std::shared_ptr<Game> createGame(GameMode gameId, PlayMode playerSelection);

};


#endif //LIVL_MENUCONTROLLER_H
