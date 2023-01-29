//
// Created by Franck GUTMANN on 29/01/2023.
//

#ifndef LIVL_GAMEEVALUATOR_H
#define LIVL_GAMEEVALUATOR_H

#include "models/PlayerId.h"
#include "models/Token.h"
#include "models/Grid.h"

class GameEvaluator {

public:
    virtual bool hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) = 0;
    [[nodiscard]] virtual PlayerId getWinner(const Grid<Token> &grid) const = 0;

};

#endif //LIVL_GAMEEVALUATOR_H
