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
    inline static std::vector<std::string> playerList = std::vector<std::string> {
        "Human vs Human", "Human vs Computer"
    };

protected:
    std::shared_ptr<Menu> menuWindow;
};

#endif //LIVL_MENUINTERACTIONS_H
