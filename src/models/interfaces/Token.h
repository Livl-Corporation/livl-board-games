//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_TOKEN_H
#define LIVL_TOKEN_H


#include "models/interfaces/Player.h"

typedef unsigned int TokenType;

class Token {

public:

    Token() = default;
    Token(const PlayerId playerId, const TokenType _type) : playerId(playerId), type(_type) {}
    ~Token() = default;
    [[nodiscard]] PlayerId getPlayerId() const { return this->playerId; } ;
    [[nodiscard]] TokenType getType() const { return this->type; } ;
    void setType(TokenType _type) { this->type = _type; };

private:

    unsigned int type;
    PlayerId playerId;

};


#endif //LIVL_TOKEN_H
