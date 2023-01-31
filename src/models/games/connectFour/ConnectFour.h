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
    explicit ConnectFour(std::istream &stream);
    [[nodiscard]] static int firstRowAvailableInCol(const std::shared_ptr<Grid<Token>> &grid, int col) ;
    void initPlayers() override;
    void initPlayers(std::istream &stream) override;
protected:
    void onPositionSelected(const Position &position) override;

private:
    static constexpr GridSize colCount = 7;
    static constexpr GridSize rowCount = 6;
};


#endif //LIVL_CONNECTFOUR_H
