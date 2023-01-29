//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "MenuController.h"

void MenuController::onGameChoose(GameMode gameSelection, PlayMode playerSelection, const std::shared_ptr<GameView>& gameView) {
    // View instanced in MenuView & passed in parameters as gameView

    auto game = createGame(gameSelection, playerSelection);

    GameController gameController(game);

    // View observes game model
    game->attach((std::shared_ptr<GameObserver> &) gameView);

    // View interact with controller
    gameView->setController(std::make_shared<GameController>(gameController));

    // Display & start game
    gameView->show();
    gameController.start();
}

std::shared_ptr<Game> MenuController::createGame(GameMode gameMode, PlayMode playerSelection) {
    switch (gameMode) {
        case GameMode::TICTACTOE:
            return std::make_shared<TicTacToe>(playerSelection);
        case GameMode::CONNECT4:
            return std::make_shared<ConnectFour>(playerSelection);
        default:
            return nullptr;
    }

}
