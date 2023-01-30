//
// Created by Franck GUTMANN on 18/01/2023.
//

#include <QDebug>
#include "GameController.h"

void GameController::start() {
    qDebug() << "GameController::start()";
    this->game->notifyGameName();
    this->game->notifyPlayers();
    this->game->notifyGrid();
    this->game->nextRound();
}

void GameController::onPositionSelected(const Position &position) {
    qDebug() << "GameController::onPositionSelected() with position row : " << position.row << " , col : " << position.col << "\n";
    std::shared_ptr<Player> currentPlayer = this->game->getCurrentPlayer();
    if (currentPlayer->canInteract()) {
        currentPlayer->onPositionSelected(position);
    }
}
