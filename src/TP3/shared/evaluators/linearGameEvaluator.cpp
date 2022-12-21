#include "linearGameEvaluator.hpp"

bool LinearGameEvaluator::hasGameEnded()
{

    if (this->hasPlayerWon(1))
    {
        this->winner = 1;
    }
    else if (this->hasPlayerWon(2))
    {
        this->winner = 2;
    }

    return this->winner != NO_PLAYER || this->getGrid()->isFull();
}

PlayerId LinearGameEvaluator::getWinner() const
{
    return winner;
}

bool LinearGameEvaluator::hasPlayerWon(const PlayerId id) const
{
    unsigned int maxConsecutive = 0;

    checkRows(id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    checkColumns(id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    checkDiagonals(id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    return false;
}

void LinearGameEvaluator::checkRows(const PlayerId id, unsigned int &maxConsecutive) const
{
    for (unsigned int row = 0; row < this->getGrid()->getYSize(); row++)
    {
        checkMaxConsecutive(id, row, 0, 0, 1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkColumns(const PlayerId id, unsigned int &maxConsecutive) const
{
    for (unsigned int col = 0; col < this->getGrid()->getXSize(); col++)
    {
        checkMaxConsecutive(id, 0, col, 1, 0, maxConsecutive);
    }
}

void LinearGameEvaluator::checkDiagonals(const PlayerId id, unsigned int &maxConsecutive) const
{
    unsigned int maxCol = this->getGrid()->getXSize() - this->getGrid()->getYSize();
    for (unsigned int startCol = 0; startCol <= maxCol; startCol++)
    {
        checkMaxConsecutive(id, 0, startCol, 1, 1, maxConsecutive);
        checkMaxConsecutive(id, 0, startCol, 1, -1, maxConsecutive);
        checkMaxConsecutive(id, this->getGrid()->getYSize() - 1, startCol, -1, 1, maxConsecutive);
        checkMaxConsecutive(id, this->getGrid()->getYSize() - 1, startCol, -1, -1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkMaxConsecutive(const PlayerId id, unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep, unsigned int &maxConsecutive) const
{
    unsigned int curMaxConsecutive = 0;
    for (int row = startRow, col = startCol; row < this->getGrid()->getYSize() && col < this->getGrid()->getXSize() && row >= 0 && col >= 0; row += rowStep, col += colStep)
    {
        if (this->getGrid()->getElementAt({col, row}) == id)
        {
            curMaxConsecutive++;
        }
        else
        {
            curMaxConsecutive = 0;
        }
    }
    if (curMaxConsecutive > maxConsecutive)
    {
        maxConsecutive = curMaxConsecutive;
    }
}
