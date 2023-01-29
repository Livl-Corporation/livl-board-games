//
// Created by Julien on 29/01/2023.
//

#include <iostream>
#include "ConnectFour.h"

ConnectFour::ConnectFour(PlayMode playMode)
: Game("Connect Four", GameMode::CONNECT4, 1, "Place your token between column (1) to (7) : ")
{
    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(4));

    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };
    ConnectFourHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<ConnectFourHumanPlayer>(p1));

    if(playMode == PlayMode::HUMAN_VS_HUMAN) {
        ConnectFourHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<ConnectFourHumanPlayer>(p2));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        ConnectFourComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<ConnectFourComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }

    Token emptyToken{};
    Grid<Token> grid1(xSize, ySize, emptyToken);
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}


void ConnectFour::nextRound() {
    incrementRound();
    Game::notifyAskForPosition();
}

void ConnectFour::onPositionSelected(Position position) {
    Token token(this->getCurrentPlayer()->getId());

    try {
        // Check if the column is valid
        if (position.x < 0 || position.x > this->getGrid()->getXSize())
        {
            throw OutOfBoundsException();
        }

        position.y = firstRowAvailableInCol(this->getGrid(), position.y);
        std::cout << "Position x: " << position.x << "Position y " << position.y << std::endl;
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

int ConnectFour::firstRowAvailableInCol(const std::shared_ptr<Grid<Token>> &grid, int col)
{
    Position position{col, static_cast<int>((grid->getYSize()-1))};

    while (!grid->isPositionEmpty(position))
    {

        if (position.y == 0)
        {
            // If there is no row available in this col, throw an exception & exit function
            throw ColumnFullException();
        }
        else
        {
            position.y--;
        }
    }

    return position.y;
}
