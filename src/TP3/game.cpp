#include "game.hpp"

Game::Game(
    const std::string name,
    const unsigned int xSize,
    const unsigned int ySize,
    const std::vector<Player> players,
    std::unique_ptr<PositionRequester> positionRequester,
    std::unique_ptr<GameEvaluator> gameEvaluator)
    : players(players), grid(xSize, ySize), name(name), positionRequester(std::move(positionRequester)), gameEvaluator(std::move(gameEvaluator))
{
    this->playerCount = players.size();
}

void Game::play()
{
    shared::printTitle(this->getName()); // Print game title

    // Play game until a player has won
    do 
    {
        this->nextRound();
        const Player player = this->nextPlayerToPlay();
        this->dropPlayerOnPosition(player);
        this->checkIfPlayerHasWon(player.getId());
    } while (!this->isFinished);
}

void Game::nextRound() 
{
    round++;
    std::ostringstream status;
    status << "Tour N° " << this->getRound();
    shared::printHeader(status.str());
}

// Determines who is playing this round
Player Game::nextPlayerToPlay() const
{
    unsigned int playerIndex = (round - 1) % playerCount;
    return players[playerIndex];
}

// Drop player on a position
void Game::dropPlayerOnPosition(const Player &player) 
{
    Position position;
    PlayerId playerId = player.getId();

    if (player.getIsComputer())
    {
        // Player is computer
        position = this->playAsComputer(playerId);
        ConsoleHandler::printOutput("Joué par l'ordinateur en " + std::to_string(position.x+1) + "," + std::to_string(position.y+1) + ".");    }
    else
    {
        // Player is a real person
        ConsoleHandler::printOutput("Joueur " + std::to_string(playerId) + ", c'est à toi !");

        // Ask him in which position he wants to place his position and place it in the grid
        do
        {
            this->getGrid().displayGrid();
            position = this->positionRequester->askForPosition(Player::getPlayerChar(playerId), this->getGrid());
        } while (!this->getGrid().place(position, playerId));
    }
}

void Game::checkIfPlayerHasWon(const PlayerId &playerId)
{
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

Position Game::playAsComputer(const PlayerId &playerId)
{
    std::vector<Position> freePositions = this->getGrid().getFreePositions();

    int positionSelected = shared::randomInt(0, freePositions.size());

    // Keep trying to place a piece on the grid until a valid position is found
    while (!this->getGrid().place(freePositions[positionSelected], playerId))
    {
        positionSelected = shared::randomInt(0, freePositions.size());
    }

    return freePositions[positionSelected];
}

void Game::win(const PlayerId &playerId)
{
    std::ostringstream msg;
    msg << "Victoire du joueur " << playerId << " (" << Player::getPlayerChar(playerId) << ")";
    shared::printTitle(msg.str());

    this->getGrid().displayGrid();

    this->isFinished = true;
}

void Game::tie()
{
    shared::printTitle(std::string("Match nul"));

    this->getGrid().displayGrid();

    this->isFinished = true;
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vect(this->players);
    return vect;
}