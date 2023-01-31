//
// Created by Franck GUTMANN on 30/01/2023.
//

#include "Othello.h"
#include "models/Grid.cpp"

Othello::Othello(PlayMode playMode) : Game("Othello", GameMode::OTHELLO, 2, "Place your token next to an opponent token to flip it.") {

    Game::setEvaluator(std::make_shared<OthelloGameEvaluator>());

    std::function<void(Position)> callback = [this](auto && PH1) { onPositionSelected(std::forward<decltype(PH1)>(PH1)); };
    OthelloHumanPlayer p1(1, "Player 1", callback);
    this->addPlayer(std::make_shared<OthelloHumanPlayer>(p1));

    if(playMode == PlayMode::HUMAN_VS_HUMAN) {
        OthelloHumanPlayer p2(2, "Player 2", callback);
        this->addPlayer(std::make_shared<OthelloHumanPlayer>(p2));
    } else if (playMode == PlayMode::HUMAN_VS_AI) {
        OthelloComputerPlayer p2(2, "BOT", callback);
        this->addPlayer(std::make_shared<OthelloComputerPlayer>(p2));
    } else {
        throw UnimplementedPlayMode();
    }

    Grid<Token> grid1 = initGrid();
    this->setGrid(std::make_shared<Grid<Token>>(grid1));
}

Grid<Token> Othello::initGrid() {
    Token emptyToken{};

    Grid<Token> grid1(rowCount, colCount, emptyToken);

    Token whiteToken{1};
    Token blackToken{2};

    grid1.place({3, 3}, whiteToken);
    grid1.place({4, 4}, whiteToken);
    grid1.place({3, 4}, blackToken);
    grid1.place({4, 3}, blackToken);

    return grid1;
}


void Othello::onPositionSelected(const Position &position) {

    if (OthelloGameEvaluator::canPlaceToken(position, getCurrentPlayer()->getId(), *getGrid())) {
        Game::onPositionSelected(position);
    } else {
        Game::notifyError("This position doesn't let you flip any token.");
        Game::notifyAskForPosition();
    }

}

void Othello::afterPlacementAction(const PlayerId &playerId, const Position &position) {
    // Check the eight possible directions from the position that the player choose to place their token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (auto direction : directions)
    {
        // Check if there are any opponent's tokens that can be flipped in this direction
        std::vector<Position> piecesToFlip = OthelloGameEvaluator::getFlippablePieces(position, playerId, direction, *getGrid());
        if (piecesToFlip.empty())
        {
            continue;
        }

        // Flip the opponent's tokens in this direction
        for (const Position &p : piecesToFlip)
        {
            Token token{playerId};
            getGrid()->replaceAt(p, token);
        }
    }
}
