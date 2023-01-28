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
#include "models/interfaces/Observable.h"

typedef unsigned int Round;

class Game : public Observable<Game> {
public:
    [[nodiscard]] inline PlayerId getPlayerId(unsigned int roundNumber) const {
        return (roundNumber - 1) % players.size();
    }

    [[nodiscard]] std::string getName() const { return this->name; };

    [[nodiscard]] Round getRound() const { return this->round; };

    [[nodiscard]] std::string getMessage() const { return this->message; };

    void setMessage(const std::string &newMessage);

    [[nodiscard]] std::shared_ptr<Grid<Token>> getGrid() const {return this->grid; }

    [[nodiscard]] std::vector<std::shared_ptr<Player>> getPlayers() const { return this->players; }

    [[nodiscard]] std::shared_ptr<Player> getCurrentPlayer() const;

    [[nodiscard]] GameMode getGameMode() const { return this->gameMode; }

    // As an observable, we need to notify observers when the game is updated
    void attach(std::shared_ptr<Observer<Game>> &_observer) override;

    void notify(const Game &value) override;

protected:
    Game(std::string  name, const GameMode gameMode) : name(std::move((name))), gameMode(gameMode) {};
    void addPlayer(const std::shared_ptr<Player> &player);
    void setGrid(std::shared_ptr<Grid<Token>> grid);

    //virtual void onPositionSelected(Position position) = 0;

private:
    std::vector<std::shared_ptr<Player>> players;
    GameMode gameMode;
    std::string name;
    std::string message;
    std::shared_ptr<Grid<Token>> grid;
    Round round = 0;
    std::shared_ptr<Observer<Game>> observer;

};


#endif //LIVL_GAME_H
