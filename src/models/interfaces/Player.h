//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_PLAYER_H
#define LIVL_PLAYER_H

#include <string>
#include <utility>
#include "models/Position.h"

typedef unsigned int PlayerId;

class Player {

public:
    [[nodiscard]] PlayerId getId() const { return this->id; };

    // On round start, start thuiking about playign ...... to meditate ...
    virtual void play() = 0;

    // Event when a position was selected
    virtual void onPositionSelected (Position position) = 0;

    virtual bool canInteract() = 0;

protected:
    Player(PlayerId id, std::string name) : id(id), name(std::move(name)) {};

private:
    PlayerId id;
    std::string name;

};

#endif //LIVL_PLAYER_H
