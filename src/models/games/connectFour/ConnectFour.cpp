//
// Created by Julien on 29/01/2023.
//

#include <QDebug>
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

void ConnectFour::onPositionSelected(Position position) {
    Token token(this->getCurrentPlayer()->getId());

    try {

        // Check if the column is valid
        if (position.col < 0 || position.col > this->getGrid()->getColCount())
        {
            throw OutOfBoundsException();
        }

        position.row = firstRowAvailableInCol(this->getGrid(), position.col);
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
    Position position{col, static_cast<int>((grid->getRowCount() - 1))};

    while (!grid->isPositionEmpty(position))
    {

        if (position.row == 0)
        {
            // If there is no row available in this col, throw an exception & exit function
            throw ColumnFullException();
        }
        else
        {
            position.row--;
        }
    }

    qDebug() << "firstRowAvailableInCol" << position.col << position.row;

    return position.row;
}
