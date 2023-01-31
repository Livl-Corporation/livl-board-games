//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERSHUMANPLAYER_H
#define LIVL_CHECKERSHUMANPLAYER_H

#include "models/interfaces/Player.h"

class CheckersHumanPlayer : public Player {
public:
    CheckersHumanPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    CheckersHumanPlayer(std::istream &stream, std::function<void(Position)> &_callback): Player(stream, _callback) {};
    bool canInteract() override { return true; };
};

#endif //LIVL_CHECKERSHUMANPLAYER_H
