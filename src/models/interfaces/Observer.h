//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_OBSERVER_H
#define LIVL_OBSERVER_H

template <typename T>
class Observer {
public:
    virtual void onChange(const T &value) = 0;
};

#endif //LIVL_OBSERVER_H