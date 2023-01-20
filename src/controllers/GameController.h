//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_GAMECONTROLLER_H
#define LIVL_GAMECONTROLLER_H


#include <memory>
#include "models/Game.h"

class GameController {

public:

    explicit GameController(const std::shared_ptr<Game> &game) : game(game) {};
    [[nodiscard]] std::shared_ptr<Game> getGame() const { return game; };
    void start();

protected:

    std::shared_ptr<Game> game;
};


#endif //LIVL_GAMECONTROLLER_H