//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "TicTacToe.h"
#include "models/Grid.cpp"
#include "models/evaluators/LinearGameEvaluator.h"

TicTacToe::TicTacToe(PlayMode playMode) : Game("TicTacToe", GameMode::TICTACTOE, playMode, 2, "Place your token between (1,1) to (3,3) : ") {

    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(3));

    this->initPlayers();

    std::shared_ptr<Token> emptyToken = std::make_shared<Token>(0);
    std::shared_ptr<Grid<Token>> grid = std::make_shared<Grid<Token>>(rowCount, colCount, emptyToken);
    this->setGrid(grid);
}

TicTacToe::TicTacToe(std::istream &stream): Game(stream) {
    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(3));
    this->initPlayers(stream);
}

void TicTacToe::initPlayers(std::istream &stream) {
    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };

    this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(stream, callback));

    if(this->playMode == PlayMode::HUMAN_VS_HUMAN) {
        this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(stream, callback));
    } else if (this->playMode == PlayMode::HUMAN_VS_AI) {
        this->addPlayer(std::make_shared<TicTacToeComputerPlayer>(stream, callback));
    } else {
        throw UnimplementedPlayMode();
    }
}

void TicTacToe::initPlayers() {
    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };
    TicTacToeHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p1));

    if(this->playMode == PlayMode::HUMAN_VS_HUMAN) {
        TicTacToeHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p2));
    } else if (this->playMode == PlayMode::HUMAN_VS_AI) {
        TicTacToeComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<TicTacToeComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }
}