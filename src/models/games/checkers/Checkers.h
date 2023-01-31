//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERS_H
#define LIVL_CHECKERS_H


#include <optional>
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

protected:
    void onPositionSelected(Position position) override;
private:
    static Grid<Token> initGrid();
    void selectOriginPosition(Position position);
    void moveOriginToPosition(Position position);

    std::optional<Position> originPosition;
    static constexpr GridSize colCount = 8;
    static constexpr GridSize rowCount = 8;
};

#endif //LIVL_CHECKERS_H
