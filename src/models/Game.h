//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_GAME_H
#define LIVL_GAME_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <memory>
#include "models/interfaces/Player.h"
#include "Token.h"
#include "models/Grid.h"
#include "models/enums/GameMode.h"
#include "models/interfaces/GameObservable.h"
#include "Round.h"
#include "models/enums/PlayMode.h"
#include "models/interfaces/GameEvaluator.h"

class Game : public GameObservable, Serializable {
public:
    [[nodiscard]] inline PlayerId getPlayerId(unsigned int roundNumber) const {
        return (roundNumber - 1) % players.size();
    }

    [[nodiscard]] std::string getName() const { return this->name; };

    [[nodiscard]] Round getRound() const { return this->round; };

    [[nodiscard]] std::shared_ptr<Grid<Token>> getGrid() {return this->grid; }

    [[nodiscard]] std::vector<std::shared_ptr<Player>> getPlayers() const { return this->players; }

    [[nodiscard]] std::shared_ptr<Player> getCurrentPlayer() const;

    [[nodiscard]] GameMode getGameMode() const { return this->gameMode; }

    [[nodiscard]] unsigned int getNumberOfInputValues() const { return this->numberOfInputValues; }

    virtual void nextRound();

    void setEvaluator(std::shared_ptr<GameEvaluator> _evaluator) { this->evaluator = std::move(_evaluator); }

    [[nodiscard]] std::shared_ptr<GameEvaluator> getEvaluator() const { return this->evaluator; }

    // As an observable, we need to notify observers when the game is updated
    void attach(std::shared_ptr<GameObserver> &_observer) override;

    void notifyError(const std::string &message) override;
    void notifyMessage(const std::string &message) override;
    void notifyAskForPosition() override;
    void notifyAskForPosition(const std::string &message) override;
    void notifyGameEnd(const std::string &message) override;

    void notifyGameName() override;
    void notifyRound() override;

    void notifyGrid() override;
    void notifyPlayers() override;

    void serialize(std::ostream &stream) override;
    void deserialize(std::istream &stream) override;

protected:
    PlayMode playMode;

    Game(std::string name, const GameMode gameMode, PlayMode playMode, unsigned int numberOfInputValues, std::string askForPositionMessage)
        : name(std::move((name))), gameMode(gameMode), playMode(playMode), numberOfInputValues(numberOfInputValues), askForPositionMessage(std::move(askForPositionMessage)) {};

    Game(std::istream &stream) { this->deserialize(stream); }

    void addPlayer(const std::shared_ptr<Player> &player);
    void setGrid(std::shared_ptr<Grid<Token>> &grid);
    void incrementRound() { this->round++; }

    void saveGame();

    virtual void onPositionSelected(const Position &position);
    virtual void afterPlacementAction(const PlayerId &playerId, const Position &position){};

    void roundEnd();
    virtual void initPlayers() = 0;
    virtual void initPlayers(std::istream &stream) = 0;

private:
    std::vector<std::shared_ptr<Player>> players;
    GameMode gameMode;
    std::string name;
    Round round = 0;
    unsigned int numberOfInputValues;
    std::string askForPositionMessage;

    std::shared_ptr<Grid<Token>> grid;
    std::shared_ptr<GameObserver> observer;
    std::shared_ptr<GameEvaluator> evaluator;

};


#endif //LIVL_GAME_H
