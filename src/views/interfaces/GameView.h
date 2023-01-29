//
// Created by Julien on 21/01/2023.
//

#ifndef LIVL_GAMEVIEW_H
#define LIVL_GAMEVIEW_H

#include "controllers/GameController.h"

class GameView : public GameObserver{
public:
    GameView() = default;

    void setController(const std::shared_ptr<GameInteraction> &value) {
        this->controller = value;
    }

    virtual void show() = 0;

    // As an observer, the view is notified when the game is updated
    void updateError(const std::string &message) override = 0;
    void updateMessage(const std::string &message) override = 0;
    void updateAskForPosition(const std::string &message, unsigned int numberOfValues) override = 0;

    void updateGameName(const std::string &gameName) override = 0;
    void updateRound(Round round, const std::shared_ptr<Player> &player) override = 0;
    void updateGrid(const Grid<Token> &grid) override = 0;
    void updatePlayers(const std::vector<std::shared_ptr<Player>> &players) override = 0;

protected:
    std::shared_ptr<GameInteraction> controller;

};

#endif //LIVL_GAMEVIEW_H
