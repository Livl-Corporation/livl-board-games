//
// Created by Franck GUTMANN on 18/01/2023.
//

#include "Game.h"
//#include "Subject.cpp"

void Game::addPlayer(const std::shared_ptr<Player> &player) {
    this->players.push_back(player);
}

void Game::setGrid(std::shared_ptr<Grid<Token>> _grid) {
    this->grid = std::move(_grid);
}

void Game::setMessage(const std::string &newMessage) {
    this->message = newMessage;
    //Subject::notify(*this);
}
