//
// Created by Julien on 30/01/2023.
//

#include "Checkers.h"

Checkers::Checkers(PlayMode playMode) : Game("Othello", GameMode::OTHELLO, 2, "Place your token next to an opponent token to flip it.") {

    Game::setEvaluator(std::make_shared<CheckersEvaluator>());

    std::function<void(Position)> callback = [this](auto &&PH1) {
        onPositionSelected(std::forward<decltype(PH1)>(PH1));
    };
    CheckersHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<CheckersHumanPlayer>(p1));

    if (playMode == PlayMode::HUMAN_VS_HUMAN) {
        CheckersHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<CheckersHumanPlayer>(p2));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        CheckersComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<CheckersComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }

    Grid<Token> grid1 = initGrid();
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}

Grid<Token> Checkers::initGrid()
{
    Token emptyToken{};

    Grid<Token> grid1(rowCount, colCount, emptyToken);

    Token whiteToken{1};
    Token blackToken{2};

    // place default token on the board for a checkers game for element 1 and 2 in horizontal direction :
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < colCount; j++) {
            if ((i + j) % 2 == 1) {
                grid1.place({i, j}, whiteToken);
            }
        }
    }
    for (int i = rowCount - 1; i > rowCount - 4; i--) {
        for (int j = 0; j < colCount; j++) {
            if ((i + j) % 2 == 1) {
                grid1.place({i, j}, blackToken);
            }
        }
    }

    return grid1;
}

void Checkers::onPositionSelected(Position position) {
    Game::onPositionSelected(position);
}


