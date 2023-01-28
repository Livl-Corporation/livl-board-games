//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEINTERACTION_H
#define LIVL_GAMEINTERACTION_H

#include "models/Position.h"

class GameInteraction {

public:
    virtual void onPositionSelected(const Position &position) = 0;

};

#endif //LIVL_GAMEINTERACTION_H
