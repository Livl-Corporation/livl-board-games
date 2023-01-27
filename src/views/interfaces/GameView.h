//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_GAMEVIEW_H
#define LIVL_GAMEVIEW_H

#include "controllers/GameController.h"

class GameView {
public:
    GameView() = default;
    virtual void show() = 0;
    void setController(const std::shared_ptr<GameController> &_controller) {
        this->controller = _controller;
    };
    virtual void attachObserver() = 0;
    //virtual std::shared_ptr<Subject<Position>> getPositionSubject() = 0;
protected:
    std::shared_ptr<GameController> controller;
};

#endif //LIVL_GAMEVIEW_H
