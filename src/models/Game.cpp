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
    notify(*this);
}

void Game::setMessage(const std::string &newMessage) {
    this->message = newMessage;
    notify(*this);
}

void Game::attach(std::shared_ptr<GameObserver<Game>> &_observer) {
    this->observer = _observer;
}

void Game::notify(const Game &value) {
    if (this->observer != nullptr) {
        this->observer->update(value);
    } else {
        qDebug() << "No observer attached to the game";
    }
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
