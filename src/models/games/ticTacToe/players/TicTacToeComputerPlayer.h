//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOECOMPUTERPLAYER_H
#define LIVL_TICTACTOECOMPUTERPLAYER_H


#include "models/interfaces/Player.h"

class TicTacToeComputerPlayer : public Player {
public :
    TicTacToeComputerPlayer(PlayerId id, std::string name) : Player(id, std::move(name)) {};
    void play() override;
    void onPositionSelected (Position position) override;
};


#endif //LIVL_TICTACTOECOMPUTERPLAYER_H
