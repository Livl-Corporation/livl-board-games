//
// Created by Franck GUTMANN on 30/01/2023.
//

#ifndef LIVL_OTHELLOHUMANPLAYER_H
#define LIVL_OTHELLOHUMANPLAYER_H


#include "models/interfaces/Player.h"

class OthelloHumanPlayer : public Player {

public:
    OthelloHumanPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    bool canInteract() override { return true; }

};


#endif //LIVL_OTHELLOHUMANPLAYER_H
