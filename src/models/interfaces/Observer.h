//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_OBSERVER_H
#define LIVL_OBSERVER_H


template <typename T>
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const T &value) = 0;
};

#endif //LIVL_OBSERVER_H
