//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_MENUCONSOLE_H
#define LIVL_MENUCONSOLE_H


#include <vector>
#include <string>
#include <memory>
#include "controllers/MenuController.h"
#include "models/MenuData.h"
#include "views/cli/ConsoleHandler.h"

class MenuConsole {
public:

    MenuConsole() = default;

    void setController(const std::shared_ptr<MenuController> &_controller) {
        this->controller = _controller;
    };

    void show();

    //void setGameView(GameMode gameSelection, PlayMode playerSelection) override;

private:
    void displayGameList(const std::vector<std::string> &gameList);

    void displayPlayerList(const std::vector<std::string> &playerList);

    std::shared_ptr<MenuController> controller;
    PlayMode playerSelection;
    GameMode gameSelection;

};


#endif //LIVL_MENUCONSOLE_H
