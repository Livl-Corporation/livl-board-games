//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_GAMEVIEW_H
#define LIVL_GAMEVIEW_H

#include "controllers/GameController.h"

class GameView : public Observer<Game>, Observable<Position> {
public:
    GameView() = default;
    virtual void show() = 0;
    void setController(const std::shared_ptr<GameController> &_controller) {
        this->controller = _controller;
    };

    // As an observer, the view is notified when the game is updated
    void update(const Game &value) override = 0;

protected:
    std::shared_ptr<GameController> controller;

private:
    // As an observable, the view notifies the controller when a position is selected
    void attach(std::shared_ptr<Observer<Position>> &_observer) override { this->observer = _observer; }
    void notify(const Position &value) override { this->observer->update(value); }

    std::shared_ptr<Observer<Position>> observer;

};

#endif //LIVL_GAMEVIEW_H
