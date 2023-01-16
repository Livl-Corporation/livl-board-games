//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_INTERACTIONSPROVIDER_H
#define LIVL_INTERACTIONSPROVIDER_H

#include <memory>
#include "../interfaces/gameInteractions.h"
#include "../interfaces/menuInteractions.h"

class InteractionsProvider {

public:
    InteractionsProvider(InteractionsProvider &other) = delete;

    void operator=(const InteractionsProvider &) = delete;

    static void init(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface);

    static std::shared_ptr<GameInteractions> &gameInterface();

    static std::shared_ptr<MenuInteractions> &menuInterface();

    explicit InteractionsProvider(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface): _gameInterface(gameInterface), _menuInterface(menuInterface) {}

protected:

    static std::shared_ptr<InteractionsProvider> singleton_;
    std::shared_ptr<GameInteractions> _gameInterface;
    std::shared_ptr<MenuInteractions> _menuInterface;

};

std::shared_ptr<InteractionsProvider> InteractionsProvider::singleton_= nullptr;

#endif //LIVL_INTERACTIONSPROVIDER_H
