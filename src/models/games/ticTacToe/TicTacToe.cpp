//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "TicTacToe.h"
#include "models/games/ticTacToe/players/TicTacToeComputerPlayer.h"
#include "models/exceptions/UnimplementedPlayMode.h"
#include "models/games/ticTacToe/players/TicTacToeHumanPlayer.h"

TicTacToe::TicTacToe(PlayMode playMode) : Game("TicTacToe", GameMode::TICTACTOE) {
    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };
    TicTacToeHumanPlayer p1(1, "Joueur 1", callback);
    this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p1));

    if(playMode == PlayMode::HUMAN_VS_HUMAN) {
        TicTacToeHumanPlayer p2(2, "Joueur 2", callback);
        this->addPlayer(std::make_shared<TicTacToeHumanPlayer>(p2));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        TicTacToeComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<TicTacToeComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }

    Token emptyToken{};
    Grid<Token> grid1(xSize, ySize, emptyToken);
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}

void TicTacToe::onPositionSelected(Position position) {
    this->notifyError("Not implemented yet " + std::to_string(position.x) + " " + std::to_string(position.y));
}
