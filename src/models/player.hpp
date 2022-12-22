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

    [[nodiscard]] inline char getId() const { return static_cast<char>(this->id); };

    [[nodiscard]] inline bool getIsComputer() const { return this->isComputer; };

    static char getPlayerChar(PlayerId playerId);

private:
    PlayerId id;
    bool isComputer;
};