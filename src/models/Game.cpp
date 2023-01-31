//
// Created by Franck GUTMANN on 18/01/2023.
//

#include <QDebug>
#include "Game.h"

void Game::addPlayer(const std::shared_ptr<Player> &player) {
    this->players.push_back(player);
}

void Game::setGrid(std::shared_ptr<Grid<Token>> &_grid) {
    this->grid = std::move(_grid);
}

void Game::attach(std::shared_ptr<GameObserver> &_observer) {
    this->observer = _observer;
}

std::shared_ptr<Player> Game::getCurrentPlayer() const {
    return this->players[getPlayerId(this->round)];
}

void Game::notifyError(const std::string &message) {
    if (this->observer != nullptr) {
        this->observer->updateError(message);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyMessage(const std::string &message) {
    if (this->observer != nullptr) {
        this->observer->updateMessage(message);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyRound() {
    if (this->observer != nullptr) {
        this->observer->updateRound(round, getCurrentPlayer());
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyGrid() {
    if (this->observer != nullptr) {
        this->observer->updateGrid(*grid);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyPlayers() {
    if (this->observer != nullptr) {
        this->observer->updatePlayers(players);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyGameName() {
    if (this->observer != nullptr) {
        this->observer->updateGameName(name);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyAskForPosition(const std::string &message) {
    this->getCurrentPlayer()->play(getGrid());
    if (this->observer != nullptr) {
        this->observer->updateAskForPosition(message, getNumberOfInputValues());
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::notifyAskForPosition() {
    notifyAskForPosition(askForPositionMessage);
}

void Game::notifyGameEnd(const std::string &message) {
    if (this->observer != nullptr) {
        this->observer->updateGameEnd(message);
    } else {
        qDebug() << "No observer attached to the game";
    }
}

void Game::nextRound() {
    incrementRound();
    notifyRound();

    this->notifyAskForPosition();
}

void Game::onPositionSelected(const Position &position) {
    PlayerId playerId = this->getCurrentPlayer()->getId();

    try {
        this->getGrid()->getElementAt(position)->setPlayerId(playerId);
        afterPlacementAction(getCurrentPlayer()->getId(), position);
        roundEnd();
    } catch (std::exception &e) {
        Game::notifyError(e.what());
        Game::notifyAskForPosition();
    }
}

void Game::saveGame() {
    std::ofstream stream;
    stream.open("save.livl");

    this->serialize(stream);

    stream.close();
}

void Game::roundEnd() {

    Game::notifyGrid();

    saveGame();

    if (this->getEvaluator()->hasGameEnded(*getGrid(), getPlayerId(getRound()-1)+1)) {

        PlayerId winner = this->getEvaluator()->getWinner(*getGrid());
        if (winner == 0) {
            Game::notifyGameEnd("Draw");
        } else {
            Game::notifyGameEnd("Player " + std::to_string(winner) + " wins");
        }

    } else {
        nextRound();
    }

}

void Game::serialize(std::ostream &stream) {
    stream << this->gameMode << std::endl;
    stream << this->name << std::endl;
    stream << this->round << std::endl;
    stream << this->numberOfInputValues << std::endl;
    stream << this->askForPositionMessage << std::endl;
    stream << this->playMode << std::endl;

    this->grid->serialize(stream);

    for(const std::shared_ptr<Player> &p : this->players) {
        p->serialize(stream);
    }
}

void Game::deserialize(std::istream &stream) {
    int tmp;

    stream >> tmp;
    this->gameMode = static_cast<GameMode>(tmp);

    stream >> this->name;
    stream >> this->round;
    stream >> this->numberOfInputValues;

    // ignores a '\n' from the beginning of the string
    // (no idea where it comes from or why it doesn't cause problems earlier with the name)
    stream.ignore();

    std::getline(stream, this->askForPositionMessage, '\n');

    stream >> tmp;
    this->playMode = static_cast<PlayMode>(tmp);

    this->grid = std::make_shared<Grid<Token>>(stream);
}