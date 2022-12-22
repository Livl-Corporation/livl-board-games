#include "game.hpp"

#include <utility>

// This tells the compiler that there is a class template called Grid that can be instantiated with any type.
template <typename T>
class Grid;

Game::Game(
    std::string name,
    const std::vector<Player>& players,
    std::unique_ptr<PositionRequester> positionRequester,
    std::unique_ptr<GameEvaluator> gameEvaluator, std::shared_ptr<Grid<PlayerId>> grid)
    : players(players), grid(std::move(grid)), name(std::move(name)), positionRequester(std::move(positionRequester)), gameEvaluator(std::move(gameEvaluator))
{
    this->playerCount = players.size();
    this->gameEvaluator->setGrid(this->grid);
    this->positionRequester->setGrid(this->grid);
}

void Game::play()
{
    ConsoleHandler::printTitle(this->getName()); // Print game title

    do
    {
        this->nextRound();
        const Player player = this->getNextPlayer();
        this->playerChoosePosition(player.getId(), player.getIsComputer());

    } while (!this->gameEvaluator->hasGameEnded(getPlayerId(this->getRound() - 1)+1));

    this->endGame();
}

void Game::endGame()
{
    PlayerId winner = this->gameEvaluator->getWinner();
    if (winner != NO_PLAYER)
    {
        ConsoleHandler::printTitle("Player's victory " + std::to_string(winner) + " (" + Player::getPlayerChar(winner) + ")");
    }
    else
    {
        ConsoleHandler::printTitle(std::string("Tie Game"));
    }

    this->getGrid()->display();
}

void Game::nextRound()
{
    round++;
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(this->getRound()));
}

PlayerId Game::getPlayerId(unsigned int roundNumber) const
{
    return (roundNumber - 1) % playerCount;
}

// Determines who is playing next
Player Game::getNextPlayer() const
{
    return players[getPlayerId(this->getRound())];
}

// Drop player on a position
void Game::playerChoosePosition(const PlayerId &playerId, const bool isComputer)
{
    Position position{};

    do
    {
        if (isComputer)
        {
            // Player is computer
            position = this->playAsComputer(playerId);
            ConsoleHandler::printLine("Played by the computer at position " + std::to_string(position.y + 1) + "," + std::to_string(position.x + 1) + ".");
        }
        else
        {
            // Player is a real person
            ConsoleHandler::printLine("Player " + std::to_string(playerId) + ", it's your turn !");

            // Ask him in which position he wants to place his position and place it in the grid
            this->getGrid()->display();
            position = this->positionRequester->askForPosition(playerId);
        }
    } while (!this->getGrid()->place(position, playerId));

    // Do something after the placement
    this->afterPlacementAction(playerId, position);
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vector(this->players);
    return vector;
}