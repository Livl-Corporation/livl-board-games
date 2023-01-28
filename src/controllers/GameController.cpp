//
// Created by Franck GUTMANN on 18/01/2023.
//

#include <QDebug>
#include "GameController.h"

void GameController::start() {
    qDebug() << "GameController::start()";
    this->game->setMessage("Game started");
}

void GameController::onPositionSelected(const Position &position) {
    qDebug() << "GameController::onPositionSelected() with position " << position.x << " " << position.y << "\n";
}
