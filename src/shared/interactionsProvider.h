//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_INTERACTIONSPROVIDER_H
#define LIVL_INTERACTIONSPROVIDER_H

#include "../interfaces/gameInteractions.h"
#include "../interfaces/menuInteractions.h"

namespace InteractionsProvider {
    inline std::shared_ptr<GameInteractions> gameInterface;
    inline std::shared_ptr<MenuInteractions> menuInterface;
}

#endif //LIVL_INTERACTIONSPROVIDER_H