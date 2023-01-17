#include "cli/gameConsoleInteractions.h"
#include "cli/menuConsoleInterface.h"
#include "gui/gameGuiInteractions.h"
#include "gui/menuGuiInteractions.h"
#include "games/gameFactory.hpp"

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
void setupConsole() {
    std::shared_ptr<GameConsoleInteractions> gameConsoleInteractions = std::make_shared<GameConsoleInteractions>();
    std::shared_ptr<MenuConsoleInteractions> menuConsoleInteractions = std::make_shared<MenuConsoleInteractions>();

    InteractionsProvider::gameInterface = gameConsoleInteractions;
    InteractionsProvider::menuInterface = menuConsoleInteractions;
}

int setupGui() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));

    std::shared_ptr<MenuGuiInteractions> menuGuiInteractions = std::make_shared<MenuGuiInteractions>();
    std::shared_ptr<GameGuiInteractions> gameGuiInteractions = std::make_shared<GameGuiInteractions>();

    InteractionsProvider::gameInterface = gameGuiInteractions;
    InteractionsProvider::menuInterface = menuGuiInteractions;

    return QApplication::exec();
}

int main(int argc, char** argv)
{

    // Run with param -console use the cli
    bool useConsole = argc > 1 && std::string(argv[1]) == "-console";
    if (useConsole) {
        setupConsole();
    } else {
        setupGui();
    }


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
