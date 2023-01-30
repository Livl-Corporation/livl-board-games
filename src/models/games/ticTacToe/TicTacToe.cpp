//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "TicTacToe.h"
#include "models/Grid.cpp"
#include "models/evaluators/LinearGameEvaluator.h"

TicTacToe::TicTacToe(PlayMode playMode) : Game("TicTacToe", GameMode::TICTACTOE, 2, "Place your token between (1,1) to (3,3) : ") {

    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(3));

    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };
    TicTacToeHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p1));

    if(playMode == PlayMode::HUMAN_VS_HUMAN) {
        TicTacToeHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p2));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        TicTacToeComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<TicTacToeComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }

    Token emptyToken{};
    Grid<Token> grid1(rowCount, colCount,emptyToken);
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}

void TicTacToe::onPositionSelected(Position position) {
    Token token(this->getCurrentPlayer()->getId());

    try {
        this->getGrid()->place(position, token);
        Game::notifyGrid();

        if (this->getEvaluator()->hasGameEnded(*getGrid(), getPlayerId(getRound()+1))) {

            PlayerId winner = this->getEvaluator()->getWinner(*getGrid());
            if (winner == 0) {
                Game::notifyGameEnd("Draw");
            } else {
                Game::notifyGameEnd("Player " + std::to_string(winner) + " wins");
            }

        } else {
            nextRound();
        }

    } catch (std::exception &e) {
        Game::notifyError(e.what());
        Game::notifyAskForPosition();
    }

}