//
// Created by Franck GUTMANN on 19/01/2023.
//

#ifndef LIVL_TICTACTOEHUMANPLAYER_H
#define LIVL_TICTACTOEHUMANPLAYER_H


#include "models/interfaces/Player.h"

class TicTacToeHumanPlayer : public Player {
public :
    TicTacToeHumanPlayer(std::istream &stream, std::function<void(Position)> &_callback): Player(stream, _callback) {};
    TicTacToeHumanPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    bool canInteract() override { return true; };
};


#endif //LIVL_TICTACTOEHUMANPLAYER_H
