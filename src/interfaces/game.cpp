#include "game.hpp"
#include "../shared/interfaceProvider.h"

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
    InterfaceProvider::getInstance()->gameInterface()->printGameInfos(this->getName(), this->getPlayers());

    do
    {
        const Player player = this->getNextPlayer();
        InterfaceProvider::getInstance()->gameInterface()->printNextRound(round, player.getId());
        this->playerChoosePosition(player.getId(), player.getIsComputer());

    } while (!this->gameEvaluator->hasGameEnded(getPlayerId(this->getRound() - 1)+1));

    this->endGame();
}

void Game::endGame()
{
    PlayerId winner = this->gameEvaluator->getWinner();
    if (winner != NO_PLAYER)
    {
        InterfaceProvider::getInstance()->gameInterface()->printWinner(winner);
    }
    else
    {
        InterfaceProvider::getInstance()->gameInterface()->printDraw();
    }

    InterfaceProvider::getInstance()->gameInterface()->printGrid(this->getGrid());
}


PlayerId Game::getPlayerId(unsigned int roundNumber) const
{
    return (roundNumber - 1) % playerCount;
}

// Determines who is playing next
Player Game::getNextPlayer()
{
    round++;
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
            InterfaceProvider::getInstance()->gameInterface()->printInfo("Played by the computer at position " + std::to_string(position.y + 1) + "," + std::to_string(position.x + 1) + ".");
        }
        else
        {
            // Player is a real person
            InterfaceProvider::getInstance()->gameInterface()->printInfo("Player " + std::to_string(playerId) + ", it's your turn !");

            // Ask him in which position he wants to place his position and place it in the grid
            InterfaceProvider::getInstance()->gameInterface()->printGrid(this->getGrid());
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