//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_PLAYER_H
#define LIVL_PLAYER_H

#include <string>
#include <utility>
#include <memory>
#include <functional>
#include "models/Position.h"
#include "models/Token.h"
#include "models/Grid.h"
#include "models/PlayerId.h"

class Player: Serializable {

public:

    [[nodiscard]] PlayerId getId() const { return this->id; };

    [[nodiscard]] std::string getName() const { return this->name; };

    // On round start, start thuiking about playign ...... to meditate ...
    virtual void play(const std::shared_ptr<Grid<Token>> &grid) {};

    // Event when a position was selected
    inline void onPositionSelected (Position position) {
        this->onPositionSelectedCallback(position);
    }

    void serialize(std::ostream &stream) override {
        stream << this->id << std::endl;
        stream << this->name << std::endl;
    }
    void deserialize(std::istream &stream) override {
        stream >> this->id;

        stream.ignore();

        std::getline(stream, this->name, '\n');
    }

    virtual bool canInteract() = 0;

protected:
    Player(PlayerId id, std::string name, std::function<void(Position)> &_callback) : id(id), name(std::move(name)), onPositionSelectedCallback(_callback) {};
    Player(std::istream &stream, std::function<void(Position)> &_callback): onPositionSelectedCallback(_callback) { this->deserialize(stream); }
    std::function<void(Position)> onPositionSelectedCallback;

private:
    PlayerId id;
    std::string name;
};

#endif //LIVL_PLAYER_H
