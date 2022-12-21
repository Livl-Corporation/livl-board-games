#include "game.hpp"

// This tells the compiler that there is a class template called Grid that can be instantiated with any type.
template <typename T>
class Grid;

Game::Game(
    const std::string name,
    const std::vector<Player> players,
    std::unique_ptr<PositionRequester> positionRequester,
    std::unique_ptr<GameEvaluator> gameEvaluator, std::shared_ptr<Grid<PlayerId>> grid)
    : players(players), grid(grid), name(name), positionRequester(std::move(positionRequester)), gameEvaluator(std::move(gameEvaluator))
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
    ConsoleHandler::printHeader("Round N° " + std::to_string(this->getRound()));
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