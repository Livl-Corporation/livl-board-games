#include <memory>
#include "interfaces/game.hpp"
#include "models/player.hpp"
#include "games/gameFactory.hpp"
#include "cli/gameConsoleInteractions.h"
#include "shared/interactionsProvider.h"
#include "cli/menuConsoleInterface.h"
#include "gui/gameGuiInteractions.h"
#include "gui/menuGuiInteractions.h"

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

        InteractionsProvider::init(gameConsoleInteractions, menuConsoleInteractions);

    } else {

        std::shared_ptr<GameGuiInteractions> gameGuiInteractions = std::make_shared<GameGuiInteractions>();
        std::shared_ptr<MenuGuiInteractions> menuGuiInteractions = std::make_shared<MenuGuiInteractions>();

        InteractionsProvider::init(gameGuiInteractions, menuGuiInteractions);

    }

    // Open main menu
    InteractionsProvider::menuInterface()->printMenu(
        GameFactory::getGameList(),
        GameFactory::getPlayerList()
        );


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
