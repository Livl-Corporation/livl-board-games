//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOE_H
#define LIVL_TICTACTOE_H

#include "models/enums/GameMode.h"
#include "models/enums/PlayMode.h"
#include "models/Game.h"


class TicTacToe : public Game {
public:
    TicTacToe(PlayMode playMode);
private:
    static constexpr GridSize xSize = 3;
    static constexpr GridSize ySize = 3;
};


#endif //LIVL_TICTACTOE_H
