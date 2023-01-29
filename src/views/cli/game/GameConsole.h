//
// Created by Julien on 23/01/2023.
//

#ifndef LIVL_GAMECONSOLE_H
#define LIVL_GAMECONSOLE_H


#include <string>
#include <memory>
#include <vector>
#include "models/interfaces/Player.h"
#include "models/Token.h"
#include "models/Grid.h"
#include "views/interfaces/GameView.h"
#include "controllers/GameController.h"
#include "views/cli/ConsoleHandler.h"

class GameConsole : public GameView {
public:
    void show() override;

    // As an observer, the view is notified when the game is updated
    void updateError(const std::string &message) override;
    void updateMessage(const std::string &message) override;
    void updateAskForPosition(const std::string &message, unsigned int numberOfValues) override;
    void updateGameEnd(const std::string &message) override;

    void updateGameName(const std::string &gameName) override;
    void updateRound(Round round, const std::shared_ptr<Player> &player) override;
    void updateGrid(const Grid<Token> &grid) override;
    void updatePlayers(const std::vector<std::shared_ptr<Player>> &players) override;

};


#endif //LIVL_GAMECONSOLE_H
