//
// Created by Franck GUTMANN on 30/01/2023.
//

#ifndef LIVL_OTHELLOCOMPUTERPLAYER_H
#define LIVL_OTHELLOCOMPUTERPLAYER_H


#include "models/interfaces/Player.h"
#include "models/evaluators/OthelloGameEvaluator.h"

class OthelloComputerPlayer : public Player {

public:
    OthelloComputerPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    OthelloComputerPlayer(std::istream &stream, std::function<void(Position)> &_callback): Player(stream, _callback) {};
    void play(const std::shared_ptr<Grid<Token>> &grid) override;
    bool canInteract() override { return false; };

};


#endif //LIVL_OTHELLOCOMPUTERPLAYER_H
