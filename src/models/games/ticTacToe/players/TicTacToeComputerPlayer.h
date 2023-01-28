//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOECOMPUTERPLAYER_H
#define LIVL_TICTACTOECOMPUTERPLAYER_H

#include "models/interfaces/Player.h"
#include "shared/Shared.hpp"
#include "models/Grid.h"
#include "models/interfaces/Token.h"

class TicTacToeComputerPlayer : public Player {
public :
    TicTacToeComputerPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    void play(const std::shared_ptr<Grid<Token>> &grid) override;
    bool canInteract() override { return false; };
};


#endif //LIVL_TICTACTOECOMPUTERPLAYER_H
