//
// Created by Franck GUTMANN on 31/01/2023.
//

#ifndef LIVL_CHECKERSTOKEN_H
#define LIVL_CHECKERSTOKEN_H

#include "CheckersTokenType.h"
#include "models/Token.h"

class CheckersToken : public Token {

public:
    CheckersToken() : Token(0) {
        qDebug() << "CheckersToken created";
    };
    explicit CheckersToken(const PlayerId playerId) : Token(playerId) {
        qDebug() << "CheckersToken created";
    };

    std::string getDisplayString() const override;

    // TODO : Check if serialization is needed
};

#endif //LIVL_CHECKERSTOKEN_H
