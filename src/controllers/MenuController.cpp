//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "MenuController.h"

void MenuController::onPlayClicked(GameMode gameSelection, PlayMode playerSelection) {

    auto game = createGame(gameSelection, playerSelection);

    GameController gameController(game);
    gameWindow.setController(std::make_shared<GameController>(gameController));
    gameWindow.show();
    gameController.start();

    qDebug() << "Game started";

}

std::shared_ptr<Game> MenuController::createGame(GameMode gameId, PlayMode playerSelection) {
    return std::make_shared<TicTacToe>(playerSelection);
}
