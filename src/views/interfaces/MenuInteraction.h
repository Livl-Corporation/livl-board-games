//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_MENUINTERACTION_H
#define LIVL_MENUINTERACTION_H

#include "models/enums/GameMode.h"
#include "models/enums/PlayMode.h"

class MenuInteraction {
public:
    virtual void setGameView(GameMode gameSelection, PlayMode playerSelection) = 0;
};

#endif //LIVL_MENUINTERACTION_H
