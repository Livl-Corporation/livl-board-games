//
// Created by Franck GUTMANN on 29/01/2023.
//

#include "Token.h"

char Token::getDisplayChar() const {
    // Return X for player 1, O for player 2, and space for empty
    return this->playerId == 1 ? 'X' : this->playerId == 2 ? 'O' : ' ';
}

std::string Token::getDisplayColor() const {
    // Return black for p1, white for p2, and empty for empty
    return this->playerId == 1 ? "black" : this->playerId == 2 ? "white" : "";
}

void Token::serialize(std::ostream &stream) {
    stream << type << std::endl;
    stream << playerId << std::endl;
}

void Token::deserialize(std::istream &stream) {
    stream >> type;
    stream >> playerId;
}



