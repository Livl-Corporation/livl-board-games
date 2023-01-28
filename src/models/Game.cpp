//
// Created by Franck GUTMANN on 18/01/2023.
//

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

void Game::attach(std::shared_ptr<Observer<Game>> &_observer) {
    this->observer = _observer;
}

void Game::notify(const Game &value) {
    this->observer->update(value);
}
