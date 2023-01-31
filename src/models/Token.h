//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_TOKEN_H
#define LIVL_TOKEN_H

#include <string>
#include <QDebug>
#include "models/PlayerId.h"
#include "interfaces/Serializable.h"

typedef unsigned int TokenType;

class Token : Serializable {

public:

    Token() : playerId(0), type(0) {
        qDebug() << "Token created";
    }
    explicit Token(const PlayerId playerId) : playerId(playerId), type(0) {
        qDebug() << "Token created";
    }
    Token(const PlayerId playerId, const TokenType _type) : playerId(playerId), type(_type) {
        qDebug() << "Token created";
    }
    explicit Token(std::istream &stream) { this->deserialize(stream); }

    ~Token() = default;
    [[nodiscard]] PlayerId getPlayerId() const { return this->playerId; } ;
    void setPlayerId(PlayerId _playerId) {
        this->playerId = _playerId;
    };

    [[nodiscard]] TokenType getType() const { return this->type; } ;
    void setType(TokenType _type) { this->type = _type;};

    bool operator == (const Token &other) const
    {
        return this->playerId == other.playerId && this->type == other.type;
    }

    virtual std::string getDisplayString() const;
    virtual std::string getDisplayColor() const;

    void serialize(std::ostream &stream) override;
    void deserialize(std::istream &stream) override;
private:

    TokenType type;
    PlayerId playerId;

};

#endif //LIVL_TOKEN_H
