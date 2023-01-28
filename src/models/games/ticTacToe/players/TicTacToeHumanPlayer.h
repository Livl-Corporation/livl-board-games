//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOEHUMANPLAYER_H
#define LIVL_TICTACTOEHUMANPLAYER_H


#include "models/interfaces/Player.h"

class TicTacToeHumanPlayer : public Player {
public :
    TicTacToeHumanPlayer(PlayerId id, std::string name) : Player(id, std::move(name)) {};
    void play() override;
    void onPositionSelected (Position position) override;
    bool canInteract() override { return true; };
};


#endif //LIVL_TICTACTOEHUMANPLAYER_H
