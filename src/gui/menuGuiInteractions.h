//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_MENUGUIINTERACTIONS_H
#define LIVL_MENUGUIINTERACTIONS_H

#include "../interfaces/menuInteractions.h"

class MenuGuiInteractions : public MenuInteractions {

public:

    MenuGuiInteractions();

    void printMenu(const std::vector<std::string> &gameList, const std::vector<std::string> &playerList) const override;

};

#endif //LIVL_MENUGUIINTERACTIONS_H
