#include <memory>
#include "interfaces/game.hpp"
#include "cli/consoleHandler.hpp"
#include "models/player.hpp"
#include "games/gameFactory.hpp"
#include "cli/gameConsoleInteractions.h"
#include "shared/interfaceProvider.h"
#include "cli/menuConsoleInterface.h"

// Function to create players based on the given player selection
/*
std::vector<Player> createPlayers(unsigned int playerSelection)
{
    std::vector<Player> players;
    Player p1(1, false);
    Player p2(2, playerSelection == 1);
    players.push_back(p1);
    players.push_back(p2);
    return players;
}

// Function to play the given game
void playGame(std::unique_ptr<Game> game)
{
    game->play();
    ConsoleHandler::printHeader("GAME FINISHED");
}
*/

int main(int argc, char** argv)
{

    // Run with param -console use the cli
    if (argc > 1 && std::string(argv[1]) == "-console") {

        std::shared_ptr<GameConsoleInteractions> gameConsoleInteractions = std::make_shared<GameConsoleInteractions>();
        std::shared_ptr<MenuConsoleInteractions> menuConsoleInteractions = std::make_shared<MenuConsoleInteractions>();

        InterfaceProvider::init(gameConsoleInteractions, menuConsoleInteractions);

    } else {

        std::shared_ptr<GameConsoleInteractions> gameConsoleInteractions = std::make_shared<GameConsoleInteractions>();
        std::shared_ptr<MenuConsoleInteractions> menuConsoleInteractions = std::make_shared<MenuConsoleInteractions>();

        InterfaceProvider::init(gameConsoleInteractions, menuConsoleInteractions);

    }

    //

/*    while (true)
    {
        // Ask for player selection
        unsigned int playerSelection = getPlayerSelection();

        // Exit if the player selection is invalid
        if (playerSelection > 2 || playerSelection < 1)
            return EXIT_SUCCESS;

        // Create players
        std::vector<Player> players = createPlayers(playerSelection);

        // Ask for game selection
        unsigned int gameSelection = getGameSelection();

        // Create the requested game
        std::unique_ptr<Game> game = GameFactory::createGame(gameSelection, players);

        if (!game)
            return EXIT_SUCCESS; // if return nullptr, exit

        // Launch game
        playGame(std::move(game));
    }*/
}
