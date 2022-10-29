#pragma once

class Symbol
{
public:
    /**
     * @brief Construct a new Symbol object
     *
     * @param symbol
     */
    Symbol(char symbol, bool isComputer)
    {
        this->symbol = symbol;
        this->isComputer = isComputer;
    }

    /**
     * @brief Get symbol character
     *
     * @return char
     */
    inline char getSymbol() const { return this->symbol; };

    /**
     * @brief Get symbol Is Computer
     *
     * @return true
     * @return false
     */
    inline bool getIsComputer() const { return this->isComputer; };

    static const Symbol empty;

private:
    char symbol;
    bool isComputer;
};