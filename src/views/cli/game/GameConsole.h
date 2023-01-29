//
// Created by Julien on 23/01/2023.
//

#ifndef LIVL_GAMECONSOLE_H
#define LIVL_GAMECONSOLE_H


#include <string>
#include <memory>
#include <vector>
#include "models/interfaces/Player.h"
#include "models/interfaces/Token.h"
#include "models/Grid.h"
#include "views/interfaces/GameView.h"
#include "controllers/GameController.h"
#include "views/cli/ConsoleHandler.h"

class GameConsole : public GameView {
public:
    void show() override;
    GameConsole* getGameConsole() { return this;}

    // As an observer, the view is notified when the game is updated
    //void update(const Game &value) override;
    void updateError(const std::string &message) override;
    void updateMessage(const std::string &message) override;
    void updateRound(Round round) override;

    void printGameInfos(const std::string &gameName, const std::vector<std::shared_ptr<Player>> &players) const;
    void printGrid(const Grid<Token> &grid) const ;
    void printNextRound(const Player &player, unsigned int round) const;
    void printInfo(const std::string &message) const;
    void printError(const std::string &message) const;
    void printWinner(const PlayerId &playerId) const;
    void printDraw() const;
    void printComputerPlay() const;

};


#endif //LIVL_GAMECONSOLE_H
