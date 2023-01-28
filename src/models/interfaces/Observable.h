//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_OBSERVABLE_H
#define LIVL_OBSERVABLE_H

#include <memory>
#include "Observer.h"

template <typename T>
class Observable {
public:
    virtual void attach(std::shared_ptr<Observer<T>> observer) = 0;
    virtual void notify(const T &value) = 0;

};

#endif //LIVL_OBSERVABLE_H

