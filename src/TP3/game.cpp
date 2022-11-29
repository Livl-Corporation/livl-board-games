#include "game.hpp"

Game::Game(
    const std::string name,
    const unsigned int xSize,
    const unsigned int ySize,
    const std::vector<Player> players) : players(players), grid(xSize, ySize), name(name),
                                         // theses members will be initialized by each games :
                                         cellRequester(nullptr), gameEvaluator(nullptr)
{
    this->playerCount = players.size();
}

void Game::play()
{

    printTitle(this->getName());

    do
    {
        this->nextRound();
    } while (!this->isFinished);
}

void Game::nextRound()
{
    round++;
    std::ostringstream status;
    status << "Tour N° " << this->getRound();
    printHeader(status.str());

    // Determines who is playing this round
    unsigned int playerIndex = (round - 1) % playerCount;
    Player player = players[playerIndex];
    int playerId = player.getId();

    if (player.getIsComputer())
    {
        // Player is computer
        Cell cell = this->playAsComputer(playerId);
        std::cout << "Joué par l'ordinateur en " << cell.x << "," << cell.y << "." << std::endl;
    }
    else
    {
        // Player is a real person
        std::cout << "Joueur " << playerId << ", c'est à toi !" << std::endl;

        // Ask him in which cell he wants to place his cell and place it in the grid
        Cell cell;
        do
        {
            this->getGrid().displayGrid();
            cell = this->cellRequester->askForCell(getPlayerChar(playerId));
        } while (!this->getGrid().place(cell, playerId));
    }

    // Verify if player has won
    if (this->gameEvaluator->hasPlayerWon(playerId, this->getGrid()))
    {
        win(playerId);
    }
    else if (this->getGrid().isGridFull())
    {
        // If grid is full, tie
        tie();
    }
}

Cell Game::playAsComputer(const unsigned int playerId)
{
    std::vector<Cell> freeCells = this->getGrid().getFreeCells();

    int cellSelected = randomInt(0, freeCells.size());

    this->getGrid().place(freeCells[cellSelected], playerId);

    return freeCells[cellSelected];
}

void Game::win(int playerId)
{
    std::ostringstream msg;
    msg << "Victoire du joueur " << playerId << " (" << getPlayerChar(playerId) << ")";
    printTitle(msg.str());

    this->getGrid().displayGrid();

    this->isFinished = true;
}

void Game::tie()
{
    printTitle(std::string("Match nul"));

    this->getGrid().displayGrid();

    this->isFinished = true;
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vect(this->players);
    return vect;
}