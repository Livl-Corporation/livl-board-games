//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_GAMECONTROLLER_H
#define LIVL_GAMECONTROLLER_H


#include <memory>
#include "models/Game.h"
#include "views/interfaces/GameInteraction.h"

class GameController : public Observer<Position>, public GameInteraction {

public:

    explicit GameController(const std::shared_ptr<Game> &game) : game(game) {};
    [[nodiscard]] std::shared_ptr<Game> getGame() const { return game; };
    void start();

    // As an observer, the controller is notified when a position is selected
    void update(const Position &value) override;

    // Game interaction
    void onPositionSelected(const Position &position) override;

protected:

    std::shared_ptr<Game> game;
};


#endif //LIVL_GAMECONTROLLER_H
