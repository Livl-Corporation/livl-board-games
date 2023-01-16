//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "interfaceProvider.h"

InterfaceProvider *InterfaceProvider::getInstance() {
    if (!singleton_) {
        throw std::runtime_error("InterfaceProvider not initialized");
    }
    return singleton_;
}

void *InterfaceProvider::init(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface) {
    singleton_ = new InterfaceProvider(gameInterface, menuInterface);
}

const std::shared_ptr<GameInteractions> &InterfaceProvider::gameInterface() const {
    return _gameInterface;
}

const std::shared_ptr<MenuInteractions> &InterfaceProvider::menuInterface() const {
    return _menuInterface;
}