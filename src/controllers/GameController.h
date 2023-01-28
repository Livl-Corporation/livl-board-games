//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_GAMECONTROLLER_H
#define LIVL_GAMECONTROLLER_H


#include <memory>
#include "models/Game.h"

class GameController : public Observer<Position> {

public:

    explicit GameController(const std::shared_ptr<Game> &game) : game(game) {};
    [[nodiscard]] std::shared_ptr<Game> getGame() const { return game; };
    void start();

    // As an observer, the controller is notified when a position is selected
    void update(const Position &value) override;

protected:

    std::shared_ptr<Game> game;
};


#endif //LIVL_GAMECONTROLLER_H
