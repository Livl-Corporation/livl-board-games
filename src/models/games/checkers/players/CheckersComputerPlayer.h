//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERSCOMPUTERPLAYER_H
#define LIVL_CHECKERSCOMPUTERPLAYER_H


#include <optional>
#include "models/interfaces/Player.h"
#include "models/evaluators/CheckersEvaluator.h"

class CheckersComputerPlayer : public Player {
public:
    CheckersComputerPlayer(PlayerId id, std::string name, std::function<void(Position)> &_callback) : Player(id, std::move(name), _callback) {};
    CheckersComputerPlayer(std::istream &stream, std::function<void(Position)> &_callback): Player(stream, _callback) {};
    void play(const std::shared_ptr<Grid<Token>> &grid) override;
    bool canInteract() override { return false; };
    void getBothDestination(const std::shared_ptr<Grid<Token>> &grid);
    std::optional<Position> destinationPosition;
    std::optional<Position> originPosition;
    bool isOriginPositionSelected = false;
};


#endif //LIVL_CHECKERSCOMPUTERPLAYER_H
