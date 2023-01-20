//
// Created by Franck GUTMANN on 18/01/2023.
//

#include "Game.h"

void Game::addPlayer(const std::shared_ptr<Player> &player) {
    this->players.push_back(player);
}

void Game::setGrid(std::shared_ptr<Grid<Token>> _grid) {
    this->grid = std::move(_grid);
}
