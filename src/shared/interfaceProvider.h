//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_INTERFACEPROVIDER_H
#define LIVL_INTERFACEPROVIDER_H

#include <memory>
#include "../interfaces/gameInterface.h"

class InterfaceProvider {

public:
    InterfaceProvider(InterfaceProvider &other) = delete;

    void operator=(const InterfaceProvider &) = delete;

    void setGameInterface(const std::shared_ptr<GameInterface> &gameInterface) {
        this->_value = gameInterface;
    }

    static InterfaceProvider *getInstance();

    static void *init(const std::shared_ptr<GameInterface> &gameInterface);


protected:

    explicit InterfaceProvider(const std::shared_ptr<GameInterface> &value): _value(value)
    {
    }

    static InterfaceProvider* singleton_;
    std::shared_ptr<GameInterface> _value;

};

InterfaceProvider* InterfaceProvider::singleton_= nullptr;

#endif //LIVL_INTERFACEPROVIDER_H
