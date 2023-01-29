//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOE_H
#define LIVL_TICTACTOE_H

#include "models/enums/GameMode.h"
#include "models/enums/PlayMode.h"
#include "models/Game.h"
#include "models/games/ticTacToe/players/TicTacToeComputerPlayer.h"
#include "models/games/ticTacToe/players/TicTacToeHumanPlayer.h"
#include "models/exceptions/UnimplementedPlayMode.h"

class TicTacToe : public Game {
public:
    explicit TicTacToe(PlayMode playMode);

protected:
    void onPositionSelected(Position position) override;

    void nextRound() override;

private:
    static constexpr GridSize xSize = 3;
    static constexpr GridSize ySize = 3;
};


#endif //LIVL_TICTACTOE_H
