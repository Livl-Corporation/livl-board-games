//
// Created by Julien on 29/01/2023.
//

#ifndef LIVL_CONNECTFOURHUMANPLAYER_H
#define LIVL_CONNECTFOURHUMANPLAYER_H


#include "models/interfaces/Player.h"

class ConnectFourHumanPlayer : public Player {
public:
    ConnectFourHumanPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    ConnectFourHumanPlayer(std::istream &stream, std::function<void(Position)> &_callback) : Player(stream, _callback) {};

    bool canInteract() override { return true; };
};


#endif //LIVL_CONNECTFOURHUMANPLAYER_H
