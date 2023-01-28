//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_GAMEVIEW_H
#define LIVL_GAMEVIEW_H

#include "controllers/GameController.h"

class GameView : public GameObserver<Game> {
public:
    GameView() = default;

    void setController(const std::shared_ptr<GameInteraction> &value) {
        this->controller = value;
    }

    virtual void show() = 0;

    // As an observer, the view is notified when the game is updated
    void update(const Game &value) override = 0;
    void updateError(const std::string &message) override = 0;

protected:
    std::shared_ptr<GameInteraction> controller;

};

#endif //LIVL_GAMEVIEW_H
