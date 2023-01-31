//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_TOKEN_H
#define LIVL_TOKEN_H

#include <string>
#include "models/PlayerId.h"
#include "interfaces/Serializable.h"

typedef unsigned int TokenType;

class Token: Serializable {

public:

    Token() = default;
    explicit Token(const PlayerId playerId) : playerId(playerId), type(0) {}
    Token(const PlayerId playerId, const TokenType _type) : playerId(playerId), type(_type) {}
    ~Token() = default;
    [[nodiscard]] PlayerId getPlayerId() const { return this->playerId; } ;
    [[nodiscard]] TokenType getType() const { return this->type; } ;
    void setType(TokenType _type) { this->type = _type; };

    bool operator == (const Token &other) const
    {
        return this->playerId == other.playerId && this->type == other.type;
    }

    [[nodiscard]] virtual char getDisplayChar() const;
    virtual std::string getDisplayColor() const;

    void serialize(std::ostream &stream) override;
    void deserialize(std::istream &stream) override;
private:

    unsigned int type;
    PlayerId playerId;

};

#endif //LIVL_TOKEN_H
