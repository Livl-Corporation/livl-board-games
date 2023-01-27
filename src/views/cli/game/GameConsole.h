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

class GameConsole : public GameView, public Observer<Game>, public std::enable_shared_from_this<GameConsole> {
public:
    void show() override;
    void attachObserver() override;
    void update(const Game &game) override;
    GameConsole* getGameConsole() { return this;}

    void printGameInfos(const std::string &gameName, const std::vector<Player> &players) const;
    void printGrid(const Grid<Token> &grid) const ;
    void printNextRound(const PlayerId &playerId, unsigned int round) const;
    void printInfo(const std::string &message) const;
    void printError(const std::string &message) const;
    void printWinner(const PlayerId &playerId) const;
    void printDraw() const;
    void printComputerPlay() const;

};


#endif //LIVL_GAMECONSOLE_H
