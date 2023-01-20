//
// Created by Julien on 18/01/2023.
//

#pragma once

#include "models/player.hpp"

class Token
{
public:
    explicit Token(PlayerId playerId, int type) : playerId(playerId), type(type) {};
    [[nodiscard]] int getType() const { return type; }
    virtual char getDisplay() const {
        return Player::getPlayerChar(playerId);
    };
    void setType(int _type) { this->type = _type; }
    [[nodiscard]] PlayerId getPlayerId() const { return playerId; }
protected:
    int type;
    PlayerId playerId;
};
