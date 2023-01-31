//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERS_H
#define LIVL_CHECKERS_H


#include <optional>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include "models/Game.h"
#include "models/enums/PlayMode.h"
#include "models/evaluators/LinearGameEvaluator.h"
#include "models/games/checkers/players/CheckersHumanPlayer.h"
#include "models/games/checkers/players/CheckersComputerPlayer.h"
#include "models/exceptions/UnimplementedPlayMode.h"
#include "models/evaluators/CheckersEvaluator.h"
#include "models/games/checkers/tokens/CheckersTokenType.h"
#include "models/games/checkers/tokens/CheckersToken.h"

class Checkers : public Game {
public:
    explicit Checkers(PlayMode playMode);
    explicit Checkers(std::istream &stream);
    void nextRound() override;

protected:
    void onPositionSelected(const Position &position) override;
    void afterPlacementAction(const PlayerId &playerId, const Position &position) override;

private:
    static Grid<Token> initGrid();
    void selectOriginPosition(const Position &position);
    void performMove(const Position &position);
    void moveOriginToPosition(const Position &position);
    void captureEnemyToken(const Position &capturableEnemyPos);

protected:
    void initPlayers() override;
    void initPlayers(std::istream &stream) override;
private:
    [[nodiscard]] bool isPositionValid(const Position &position) const;
    bool forceCaptureIfPossible();
    bool forceCaptureIfPossible(const Position &position);
    bool shouldBecomeKing(const Position &position);

    std::optional<Position> originPosition;
    std::vector<Position> validMoves;

    static constexpr GridSize colCount = 8;
    static constexpr GridSize rowCount = 8;
};

#endif //LIVL_CHECKERS_H
