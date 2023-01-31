//
// Created by Franck GUTMANN on 31/01/2023.
//

#include "CheckersToken.h"

std::string CheckersToken::getDisplayString() const {
    if (this->getType() == CheckersTokenType::KING) {
        // Return ♛ for player 1, ♕ for player 2, and space for empty
        return std::string { this->getPlayerId() == 1 ? "♛" : this->getPlayerId() == 2 ? "♕" : " " };
    }

    // Return ♟ for player 1, ♙ for player 2, and space for empty
    return std::string { this->getPlayerId() == 1 ? "♟" : this->getPlayerId() == 2 ? "♙" : " " };

}
