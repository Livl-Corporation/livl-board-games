//
// Created by Julien on 30/01/2023.
//

#include "Checkers.h"
#include <QDebug>

Checkers::Checkers(PlayMode playMode) : Game("Checkers", GameMode::OTHELLO, playMode, 2, "Select a token you want to move.") {

    Game::setEvaluator(std::make_shared<CheckersEvaluator>());
    this->initPlayers();

    Grid<Token> grid1 = initGrid();
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}

Checkers::Checkers(std::istream &stream): Game(stream) {
    Game::setEvaluator(std::make_shared<CheckersEvaluator>());
    this->initPlayers();
}

void Checkers::initPlayers(std::istream &stream) {
    std::function<void(Position)> callback = [this](auto &&PH1) {
        onPositionSelected(std::forward<decltype(PH1)>(PH1));
    };

    this->addPlayer(std::make_shared<CheckersHumanPlayer>(stream, callback));

    if (this->playMode == PlayMode::HUMAN_VS_HUMAN) {
        this->addPlayer(std::make_shared<CheckersHumanPlayer>(stream, callback));
    } else if (this->playMode == PlayMode::HUMAN_VS_AI) {
        this->addPlayer(std::make_shared<CheckersComputerPlayer>(stream, callback));
    } else {
        throw UnimplementedPlayMode();
    }
}

void Checkers::initPlayers() {
    std::function<void(Position)> callback = [this](auto &&PH1) {
        onPositionSelected(std::forward<decltype(PH1)>(PH1));
    };
    CheckersHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<CheckersHumanPlayer>(p1));

    if (this->playMode == PlayMode::HUMAN_VS_HUMAN) {
        CheckersHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<CheckersHumanPlayer>(p2));
    } else if (this->playMode == PlayMode::HUMAN_VS_AI) {
        CheckersComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<CheckersComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }
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

void Checkers::onPositionSelected(const Position &position) {
    qDebug() << "Checkers::Position selected: " << position.row << ", " << position.col;
    if (originPosition.has_value()) {
        // A position was selected, we can move the token from to originPosition to position
        performMove(position);
        originPosition.reset();
    } else {
        // No position was selected, we select the position
        selectOriginPosition(position);
    }
}

void Checkers::selectOriginPosition(const Position &position) {
    // Check if selected position is a player token
    try {

        if (this->getGrid()->getElementAt(position).getPlayerId() == this->getCurrentPlayer()->getId()) {

            validMoves = CheckersEvaluator::getValidTokenMoves(*getGrid(), position);

            // Check if the token can move
            if(validMoves.empty()) {
                throw std::invalid_argument("This token cannot move.");
            }

            originPosition = position;
            Game::notifyError("");
            Game::notifyAskForPosition("Select a destination position.");
        } else {
            throw std::invalid_argument("You must select one of your token.");
        }

    } catch (std::exception &e) {
        Game::notifyError(e.what());
        Game::notifyAskForPosition();
    }
}

void Checkers::performMove(const Position &position) {
    try {

        // Check if validPosition contains position
        if (!isPositionValid(position)) {
            throw std::invalid_argument("You must select a valid destination position.");
        }

        // Move is valid, we move the token
        moveOriginToPosition(position);

        // After placement action
        afterPlacementAction(getCurrentPlayer()->getId(), position);

        // Change player turn
        roundEnd();

    } catch (std::exception &e) {
        Game::notifyError("You must select a valid destination position.");
        Game::notifyAskForPosition("Select a destination position.");
    }
}

void Checkers::moveOriginToPosition(const Position &position) {    Token token = this->getGrid()->getElementAt(originPosition.value());
    this->getGrid()->place(position, token);
    this->getGrid()->replaceAt(originPosition.value(), Token {});
}

void Checkers::captureEnemyToken(const Position &capturableEnemyPos) {
    getGrid()->replaceAt(capturableEnemyPos, Token{});
}

void Checkers::afterPlacementAction(const PlayerId &playerId, const Position &position) {
    // Capture ennemy token if needed
    std::optional<Position> capturableEnemyPos = CheckersEvaluator::getCapturableEnemyTokenPosition(*getGrid(), getCurrentPlayer()->getId(), originPosition.value(), position);
    if (capturableEnemyPos.has_value()) {
        captureEnemyToken(capturableEnemyPos.value());
    }

    // Reset origin position
    originPosition.reset();
}

bool Checkers::isPositionValid(const Position &position) const {
    bool found = false;
    for (auto &validPosition : validMoves) {
        if (validPosition.col == position.col && validPosition.row == position.row) {
            found = true;
            break;
        }
    }
    return found;
}

bool Checkers::forceCaptureIfPossible() {
    // For each token in the grid, check if it can capture an enemy token
    for (int i = 0; i < getGrid()->getRowCount(); i++) {
        for (int j = 0; j < getGrid()->getColCount(); j++) {
            Position currentPosition{i, j};
            Token currentToken = getGrid()->getElementAt(currentPosition);
            if (currentToken.getPlayerId() == getCurrentPlayer()->getId()) {
                if (forceCaptureIfPossible(currentPosition)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Checkers::forceCaptureIfPossible(const Position &position) {
    // If no token is provided, we check for all tokens
    std::vector<Position> tokenValidMoves = CheckersEvaluator::getValidTokenMoves(*getGrid(), position);
    for (auto &validMove : tokenValidMoves) {
        std::optional<Position> capturableEnemyPos = CheckersEvaluator::getCapturableEnemyTokenPosition(*getGrid(), getCurrentPlayer()->getId(), position, validMove);
        if (capturableEnemyPos.has_value()) {
            // We can capture an enemy token, we move the token to the valid move position
            originPosition = position;
            moveOriginToPosition(validMove);
            // We capture the enemy token
            captureEnemyToken(capturableEnemyPos.value());
            // Notify player that he has captured an enemy token
            Game::notifyMessage("You have captured an enemy token at position " + std::to_string(capturableEnemyPos.value().row) + ", " + std::to_string(capturableEnemyPos.value().col));
            // We check if we can capture another enemy token
            forceCaptureIfPossible(validMove);
            return true;
        }
    }

    return false;

}

void Checkers::nextRound() {
    incrementRound();
    notifyRound();

    // Check if the current player can capture an enemy token
    if (forceCaptureIfPossible()) {
        notifyGrid();
        roundEnd();
    } else {
        this->notifyAskForPosition();
    }
}