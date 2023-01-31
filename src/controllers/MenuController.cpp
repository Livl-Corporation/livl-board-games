//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "MenuController.h"

void MenuController::onGameChoose(GameMode gameSelection, PlayMode playerSelection, const std::shared_ptr<GameView>& gameView) {
    // View instanced in MenuView & passed in parameters as gameView

    std::shared_ptr<Game> game = createGame(gameSelection, playerSelection);

    MenuController::startGame(game, gameView);
}

void MenuController::onSaveFileChoose(const std::string &saveFilePath, const std::shared_ptr<GameView> &gameView) {

    if(!std::filesystem::exists(saveFilePath)) {
        return;
    }

    std::ifstream stream;

    stream.open(saveFilePath);

    GameMode gameMode = MenuController::getGameModeFromStream(stream);
    std::shared_ptr<Game> game = createGame(gameMode, stream);

    stream.close();

    MenuController::startGame(game, gameView);
}

void MenuController::startGame(std::shared_ptr<Game> &game, const std::shared_ptr<GameView> &gameView) {

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
        case GameMode::OTHELLO:
            return std::make_shared<Othello>(playerSelection);
        case GameMode::CHECKERS:
            return std::make_shared<Checkers>(playerSelection);
        default:
            return nullptr;
    }
}

std::shared_ptr<Game> MenuController::createGame(GameMode gameMode, std::ifstream &stream) {

    switch (gameMode) {
        case GameMode::TICTACTOE:
            return std::make_shared<TicTacToe>(stream);
        case GameMode::CONNECT4:
            return std::make_shared<ConnectFour>(stream);
        case GameMode::OTHELLO:
            return std::make_shared<Othello>(stream);
        case GameMode::CHECKERS:
            return std::make_shared<Checkers>(stream);
        default:
            return nullptr;
    }
}

GameMode MenuController::getGameModeFromStream(std::ifstream &stream) {
    int res;

    stream >> res;

    stream.seekg(0); // go back to the beginning of the file

    return static_cast<GameMode>(res);
}
