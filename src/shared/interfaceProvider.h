//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_INTERFACEPROVIDER_H
#define LIVL_INTERFACEPROVIDER_H

#include <memory>
#include "../interfaces/gameInteractions.h"
#include "../interfaces/menuInteractions.h"

class InterfaceProvider {

public:
    InterfaceProvider(InterfaceProvider &other) = delete;

    void operator=(const InterfaceProvider &) = delete;

    static InterfaceProvider *getInstance();

    static void *init(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface);

    [[nodiscard]] const std::shared_ptr<GameInteractions> &gameInterface() const;

    [[nodiscard]] const std::shared_ptr<MenuInteractions> &menuInterface() const;

protected:

    explicit InterfaceProvider(const std::shared_ptr<GameInteractions> &gameInterface, const std::shared_ptr<MenuInteractions> &menuInterface): _gameInterface(gameInterface), _menuInterface(menuInterface) {}

    static InterfaceProvider* singleton_;
    std::shared_ptr<GameInteractions> _gameInterface;
    std::shared_ptr<MenuInteractions> _menuInterface;

};

InterfaceProvider* InterfaceProvider::singleton_= nullptr;

#endif //LIVL_INTERFACEPROVIDER_H
