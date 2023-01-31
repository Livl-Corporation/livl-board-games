//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERS_H
#define LIVL_CHECKERS_H


#include <optional>
#include <stdexcept>
#include <algorithm>
#include "models/Game.h"
#include "models/enums/PlayMode.h"
#include "models/evaluators/LinearGameEvaluator.h"
#include "models/games/checkers/players/CheckersHumanPlayer.h"
#include "models/games/checkers/players/CheckersComputerPlayer.h"
#include "models/exceptions/UnimplementedPlayMode.h"
#include "models/evaluators/CheckersEvaluator.h"

class Checkers : public Game {
public:
    explicit Checkers(PlayMode playMode);

private:
    static Grid<Token> initGrid();
    void selectOriginPosition(const Position &position);
    void performMove(const Position &position);
    void moveOriginToPosition(const Position &position);
    void captureEnemyToken(const Position &capturableEnemyPos);

protected:
    void onPositionSelected(const Position &position) override;
    void afterPlacementAction(const PlayerId &playerId, const Position &position) override;

private:

    std::optional<Position> originPosition;
    std::vector<Position> validMoves;

    bool isPositionValid(const Position &position) const;

    static constexpr GridSize colCount = 8;
    static constexpr GridSize rowCount = 8;
};

#endif //LIVL_CHECKERS_H
