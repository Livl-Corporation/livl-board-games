//
// Created by Julien on 29/01/2023.
//

#ifndef LIVL_CONNECTFOUR_H
#define LIVL_CONNECTFOUR_H


#include "models/Game.h"
#include "models/enums/PlayMode.h"
#include "models/evaluators/LinearGameEvaluator.h"
#include "models/games/connectFour/players/ConnectFourHumanPlayer.h"
#include "models/games/connectFour/players/ConnectFourComputerPlayer.h"
#include "models/exceptions/UnimplementedPlayMode.h"

class ConnectFour : public Game {
public:
    explicit ConnectFour(PlayMode playMode);
    [[nodiscard]] static int firstRowAvailableInCol(const std::shared_ptr<Grid<Token>> &grid, int col) ;

protected:
    void onPositionSelected(Position position) override;

    void nextRound() override;

private:
    static constexpr GridSize xSize = 7;
    static constexpr GridSize ySize = 6;
};


#endif //LIVL_CONNECTFOUR_H
