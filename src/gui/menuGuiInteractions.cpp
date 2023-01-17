//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "menuGuiInteractions.h"

MenuGuiInteractions::MenuGuiInteractions() {
    this->menuWindow = std::make_shared<Menu>();
    this->menuWindow->setGameList(GameFactory::gameList);
    this->menuWindow->setPlayerList(MenuInteractions::playerList);
    this->menuWindow->show();
}
