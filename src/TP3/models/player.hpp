#pragma once

const int NO_PLAYER = 0;
typedef unsigned int PlayerId;

class Player
{
public:
    Player(PlayerId id, bool isComputer)
    {
        this->id = id;
        this->isComputer = isComputer;
    }

    inline char getId() const { return this->id; };

    inline bool getIsComputer() const { return this->isComputer; };

    static char getPlayerChar(PlayerId playerId);

private:
    PlayerId id;
    bool isComputer;
};