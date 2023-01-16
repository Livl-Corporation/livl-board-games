//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_MENUCONSOLEINTERFACE_H
#define LIVL_MENUCONSOLEINTERFACE_H

#include "../interfaces/menuInteractions.h"

class MenuConsoleInteractions : public MenuInteractions {
public:

    MenuConsoleInteractions() = default;

    void printMenu(const std::vector<std::string> &gameList, const std::vector<std::string> &playerList) const override;

};

#endif //LIVL_MENUCONSOLEINTERFACE_H
