//
// Created by Julien on 29/01/2023.
//

#include <QDebug>
#include "ConnectFour.h"

ConnectFour::ConnectFour(PlayMode playMode)
: Game("Connect Four", GameMode::CONNECT4, playMode, 1, "Place your token between column (1) to (7) : ")
{
    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(4));

    this->initPlayers();

    std::shared_ptr<Token> emptyToken = std::make_shared<Token>(0);
    std::shared_ptr<Grid<Token>> grid1 = std::make_shared<Grid<Token>>(rowCount, colCount, emptyToken);
    this->setGrid(grid1);
}

ConnectFour::ConnectFour(std::istream &stream): Game(stream) {
    Game::setEvaluator(std::make_shared<LinearGameEvaluator>(4));
    this->initPlayers(stream);
}

void ConnectFour::initPlayers() {
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
}

void ConnectFour::initPlayers(std::istream &stream) {
    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };

    this->addPlayer(std::make_shared<ConnectFourHumanPlayer>(stream, callback));

    if(playMode == PlayMode::HUMAN_VS_HUMAN) {
        this->addPlayer(std::make_shared<ConnectFourHumanPlayer>(stream, callback));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        this->addPlayer(std::make_shared<ConnectFourComputerPlayer>(stream, callback));
    } else {
        throw UnimplementedPlayMode();
    }
}

void ConnectFour::onPositionSelected(const Position &position) {

    try {

        // Check if the column is valid
        if (position.col < 0 || position.col > this->getGrid()->getColCount())
        {
            throw OutOfBoundsException();
        }

        int row = firstRowAvailableInCol(this->getGrid(), position.col);
        qDebug() << "ConnectFour::onPositionSelected() with position row : " << position.row << " , col : " << position.col << "\n";

        Game::onPositionSelected({row, position.col});

    } catch (std::exception &e) {
        Game::notifyError(e.what());
        Game::notifyAskForPosition();
    }
}

int ConnectFour::firstRowAvailableInCol(const std::shared_ptr<Grid<Token>> &grid, int col)
{
    // Get the first available row in given colomn
    for (int row = grid->getRowCount()-1; row >= 0; row--)
    {
        if (grid->isPositionEmpty({row, col}))
        {
            qDebug() << "ConnectFour::firstRowAvailableInCol() with position row : " << row << " , col : " << col << "\n";
            return row;
        }
    }

    throw ColumnFullException();
}