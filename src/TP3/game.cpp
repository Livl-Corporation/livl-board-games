#include "game.hpp"

// This tells the compiler that there is a class template called Grid that can be instantiated with any type.
template <typename T>
class Grid;

Game::Game(
    const std::string name,
    const std::vector<Player> players,
    std::unique_ptr<PositionRequester> positionRequester,
    std::unique_ptr<GameEvaluator> gameEvaluator, std::unique_ptr<Grid<PlayerId>> grid)
    : players(players), grid(std::move(grid)), name(name), positionRequester(std::move(positionRequester)), gameEvaluator(std::move(gameEvaluator))
{
    this->playerCount = players.size();
    this->gameEvaluator->setGrid(std::move(this->grid));
    this->positionRequester->setGrid(std::move(this->grid));
}

void Game::play()
{
    ConsoleHandler::printTitle(this->getName()); // Print game title

    do
    {
        this->nextRound();
        const Player player = this->nextPlayer();
        this->playerChoosePosition(player.getId(), player.getIsComputer());
    } while (!this->gameEvaluator->hasGameEnded());

    this->endGame();
}

void Game::endGame()
{
    PlayerId winner = this->gameEvaluator->getWinner();
    if (winner != NO_PLAYER)
    {
        ConsoleHandler::printTitle("Victoire du joueur " + std::to_string(winner) + " (" + Player::getPlayerChar(winner) + ")");
    }
    else
    {
        ConsoleHandler::printTitle(std::string("Match nul"));
    }

    this->getGrid().display();
}

void Game::nextRound()
{
    round++;
    ConsoleHandler::printHeader("Tour N° " + std::to_string(this->getRound()));
}

// Determines who is playing this round
Player Game::nextPlayer() const
{
    unsigned int playerIndex = (round - 1) % playerCount;
    return players[playerIndex];
}

// Drop player on a position
void Game::playerChoosePosition(const PlayerId playerId, const bool isComputer)
{
    Position position;

    if (isComputer)
    {
        // Player is computer
        position = this->playAsComputer(playerId);
        ConsoleHandler::printLine("Joué par l'ordinateur en " + std::to_string(position.x + 1) + "," + std::to_string(position.y + 1) + ".");
    }
    else
    {
        // Player is a real person
        ConsoleHandler::printLine("Joueur " + std::to_string(playerId) + ", c'est à toi !");

        // Ask him in which position he wants to place his position and place it in the grid
        do
        {
            this->getGrid().display();
            position = this->positionRequester->askForPosition(playerId);
        } while (!this->getGrid().place(position, playerId));
    }

    // Do something after the placement
    this->afterPlacementAction(playerId, position);
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vect(this->players);
    return vect;
}