//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_MENUGUIINTERACTIONS_H
#define LIVL_MENUGUIINTERACTIONS_H

#include "../interfaces/menuInteractions.h"
#include "../games/gameFactory.hpp"
#include "gui/forms/menu/menu.h"

class MenuGuiInteractions : public MenuInteractions {

public:

    MenuGuiInteractions();

protected:
    std::shared_ptr<Menu> menuWindow;

};

#endif //LIVL_MENUGUIINTERACTIONS_H
