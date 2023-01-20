//
// Created by Julien on 18/01/2023.
//

#pragma once

#include "interfaces/token.hpp"

enum CheckersTokenType {
    NORMAL,
    KING,
};

class CheckersToken : public Token
{
public:
    char getDisplay() const override {
        if (type == CheckersTokenType::KING) {
            return Player::getPlayerChar(playerId) + 32;
        } else {
            return Player::getPlayerChar(playerId);
        }
    };
};
