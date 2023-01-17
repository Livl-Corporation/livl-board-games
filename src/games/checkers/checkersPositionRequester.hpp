#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"

class CheckersPositionRequester : public PositionRequester
{
public:
    [[nodiscard]] Position askForPosition(const PlayerId &playerId) const override;
private:
    [[nodiscard]] Position promptAndValidateDestinationPosition(const std::string &prompt, const PlayerId &playerId, const Position &from) const;
    [[nodiscard]] Position promptAndValidatePosition(const std::string &prompt, const PlayerId &playerId) const;
    [[nodiscard]] bool isMoveValid(const PlayerId &playerId, const Position &from, const Position &to) const;

    bool captureEnemyToken(const Position &from, const Position &to) const;

    bool isCaptureMove(const PlayerId &playerId, const Position &from, const Position &to) const;

    bool forceEnemyToCaptureEnemy(const PlayerId &playerId, const Position &from, Position &capturableEnemyPos) const;
};