//
// Created by Franck GUTMANN on 18/01/2023.
//

#include <QDebug>
#include "GameController.h"
#include "../models/Subject.cpp"

void GameController::start() {
    qDebug() << "GameController::start()";
    this->game->setMessage("Game started");
}
