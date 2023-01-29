//
// Created by Franck GUTMANN on 18/01/2023.
//

#include <QDebug>
#include "Game.h"

void Game::addPlayer(const std::shared_ptr<Player> &player) {
    this->players.push_back(player);
}

void Game::setGrid(std::shared_ptr<Grid<Token>> _grid) {
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

void Game::notifyRound(Round round) {
    if (this->observer != nullptr) {
        this->observer->updateRound(round);
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
