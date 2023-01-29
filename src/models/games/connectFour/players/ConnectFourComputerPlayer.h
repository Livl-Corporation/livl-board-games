//
// Created by Julien on 29/01/2023.
//

#ifndef LIVL_CONNECTFOURCOMPUTERPLAYER_H
#define LIVL_CONNECTFOURCOMPUTERPLAYER_H


#include "models/interfaces/Player.h"
#include "shared/Shared.hpp"
#include "models/exceptions/ColumnFullException.h"
#include "models/games/connectFour/ConnectFour.h"

class ConnectFourComputerPlayer : public Player {
public:
    ConnectFourComputerPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    void play(const std::shared_ptr<Grid<Token>> &grid) override;
    bool canInteract() override { return false; };
};


#endif //LIVL_CONNECTFOURCOMPUTERPLAYER_H
