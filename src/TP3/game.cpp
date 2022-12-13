#include "game.hpp"

Game::Game(
    const std::string name,
    const unsigned int xSize,
    const unsigned int ySize,
    const std::vector<Player> players,
    std::unique_ptr<PositionRequester> positionRequester,
    std::unique_ptr<GameEvaluator> gameEvaluator)
    : players(players), grid(xSize, ySize, NO_PLAYER), name(name), positionRequester(std::move(positionRequester)), gameEvaluator(std::move(gameEvaluator))
{
    this->playerCount = players.size();
}

void Game::play()
{
    ConsoleHandler::printTitle(this->getName()); // Print game title

    // Play game until a player has won
    bool isGameFinished = false;
    do
    {
        this->nextRound();
        const Player player = this->nextPlayer();
        this->dropPlayerOnPosition(player);
        isGameFinished = this->checkIfGameFinished(player.getId());
    } while (!isGameFinished);
}

void Game::nextRound()
{
    round++;
    std::ostringstream status;
    status << "Tour N° " << this->getRound();
    ConsoleHandler::printHeader(status.str());
}

// Determines who is playing this round
Player Game::nextPlayer() const
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
        ConsoleHandler::printOutput("Joué par l'ordinateur en " + std::to_string(position.x + 1) + "," + std::to_string(position.y + 1) + ".");
    }
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

bool Game::checkIfGameFinished(const PlayerId playerId)
{
    if (this->gameEvaluator->hasPlayerWon(playerId, this->getGrid()))
    {
        win(playerId);
        return true;
    }
    else if (this->getGrid().isGridFull())
    {
        // If grid is full, tie
        tie();
        return true;
    }

    return false;
}

void Game::win(const PlayerId playerId)
{
    std::ostringstream msg;
    msg << "Victoire du joueur " << playerId << " (" << Player::getPlayerChar(playerId) << ")";
    ConsoleHandler::printTitle(msg.str());
    this->getGrid().displayGrid();
}

void Game::tie()
{
    ConsoleHandler::printTitle(std::string("Match nul"));
    this->getGrid().displayGrid();
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vect(this->players);
    return vect;
}