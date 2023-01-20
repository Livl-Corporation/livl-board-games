//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_GAME_H
#define LIVL_GAME_H


#include <string>
#include <utility>
#include <vector>
#include <memory>
#include "models/interfaces/Player.h"
#include "models/interfaces/Token.h"
#include "models/Grid.h"
#include "models/enums/GameMode.h"
#include "Subject.h"

typedef unsigned int Round;

class Game : public Subject<std::shared_ptr<Game>> {
public:
    [[nodiscard]] inline PlayerId getPlayerId(unsigned int roundNumber) const {
        return (roundNumber - 1) % players.size();
    }

    [[nodiscard]] std::string getName() const { return this->name; };

    [[nodiscard]] Round getRound() const { return this->round; };

    [[nodiscard]] std::string getMessage() const { return this->message; };

    void setMessage(const std::string &newMessage) {
        this->message = newMessage;
        this->notify(std::make_shared<Game>(*this));
    }

    [[nodiscard]] std::shared_ptr<Grid<Token>> getGrid() const {return this->grid; }

    [[nodiscard]] std::vector<Player> getPlayers() const { return this->players; }

    [[nodiscard]] GameMode getGameMode() const { return this->gameMode; }

protected:
    Game(std::string  name, const GameMode gameMode) : name(std::move((name))), gameMode(gameMode) {};
    void addPlayer(const std::shared_ptr<Player> &player);
    void setGrid(std::shared_ptr<Grid<Token>> grid);

private:
    std::vector<std::shared_ptr<Player>> players;
    GameMode gameMode;
    std::string name;
    std::string message;
    std::shared_ptr<Grid<Token>> grid;
    Round round = 0;

};


#endif //LIVL_GAME_H
