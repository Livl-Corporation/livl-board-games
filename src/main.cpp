#include "cli/gameConsoleInteractions.h"
#include "cli/menuConsoleInterface.h"
#include "gui/gameGuiInteractions.h"
#include "gui/menuGuiInteractions.h"

int setupConsole() {

    InteractionsProvider::gameInterface =  std::make_shared<GameConsoleInteractions>();
    InteractionsProvider::menuInterface = std::make_shared<MenuConsoleInteractions>();

    return 0;
}

int setupGui() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));

    InteractionsProvider::gameInterface = std::make_shared<GameGuiInteractions>();
    InteractionsProvider::menuInterface = std::make_shared<MenuGuiInteractions>();

    return QApplication::exec();
}

int main(int argc, char** argv)
{

    // Run with param -console use the cli
    bool useConsole = argc > 1 && std::string(argv[1]) == "-console";
    if (useConsole) {
        return setupConsole();
    } else {
        return setupGui();
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
