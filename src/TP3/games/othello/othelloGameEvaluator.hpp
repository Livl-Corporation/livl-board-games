#pragma once

#include "../../grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class OthelloGameEvaluator : public GameEvaluator
{
public:
    OthelloGameEvaluator() : GameEvaluator()
    {
    }

    bool hasGameEnded() override;

    PlayerId getWinner() const override;
};