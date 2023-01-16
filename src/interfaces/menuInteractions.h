//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_MENUINTERACTIONS_H
#define LIVL_MENUINTERACTIONS_H

#include <string>
#include <vector>
#include "../gui/forms/menu/menu.h"

class MenuInteractions {

public:
    virtual void printMenu(const std::vector<std::string> &gameList, const std::vector<std::string> &playerList) const = 0;

protected:
    std::shared_ptr<Menu> menuWindow;
};

#endif //LIVL_MENUINTERACTIONS_H
