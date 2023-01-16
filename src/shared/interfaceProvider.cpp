//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "interfaceProvider.h"

InterfaceProvider *InterfaceProvider::getInstance() {
    return singleton_;
}

void *InterfaceProvider::init(const std::shared_ptr<GameInterface> &gameInterface) {
    singleton_ = new InterfaceProvider(gameInterface);
}
