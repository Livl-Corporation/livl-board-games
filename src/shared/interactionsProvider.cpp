//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "interactionsProvider.h"

void InteractionsProvider::init(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface) {
    singleton_ = std::make_shared<InteractionsProvider>(gameInterface, menuInterface);
}

std::shared_ptr<MenuInteractions> &InteractionsProvider::menuInterface() {
    if (!singleton_) {
        throw std::runtime_error("InteractionsProvider not initialized");
    }
    return singleton_->_menuInterface;
}

std::shared_ptr<GameInteractions> &InteractionsProvider::gameInterface() {
    if (!singleton_) {
        throw std::runtime_error("InteractionsProvider not initialized");
    }
    return singleton_->_gameInterface;
}