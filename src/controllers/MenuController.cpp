//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "MenuController.h"

void MenuController::onGameChoose(GameMode gameSelection, PlayMode playerSelection, const std::shared_ptr<GameView>& gameView) {

    auto game = createGame(gameSelection, playerSelection);

    GameController gameController(game);
    //gameController.setGameView(gameView);
    gameView->setController(std::make_shared<GameController>(gameController));
    gameView->show();
    gameView->attachObserver();
    gameController.start();
}

std::shared_ptr<Game> MenuController::createGame(GameMode gameId, PlayMode playerSelection) {
    return std::make_shared<TicTacToe>(playerSelection);
}
