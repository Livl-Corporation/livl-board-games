//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEOBSERVER_H
#define LIVL_GAMEOBSERVER_H

template <typename T>
class GameObserver {
public:
    virtual void update(const T &value) = 0;
};

#endif //LIVL_GAMEOBSERVER_H