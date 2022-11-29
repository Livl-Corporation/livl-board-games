#pragma once

const int NO_PLAYER = -1;

class Player
{
public:
    /**
     * @brief Construct a new Player object
     *
     * @param id
     * @param isComputer
     */
    Player(int id, bool isComputer)
    {
        this->id = id;
        this->isComputer = isComputer;
    }

    /**
     * @brief Get symbol character
     *
     * @return char
     */
    inline char getId() const { return this->id; };

    /**
     * @brief Get symbol Is Computer
     *
     * @return true
     * @return false
     */
    inline bool getIsComputer() const { return this->isComputer; };

private:
    int id;
    bool isComputer;
};