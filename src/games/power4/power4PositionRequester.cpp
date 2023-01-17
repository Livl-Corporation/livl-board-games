#include "power4PositionRequester.hpp"

Position Power4PositionRequester::askForPosition(const PlayerId &playerId) const
{
    int col, row;

    do
    {
        InteractionsProvider::gameInterface->printInfo("Place your token (" + std::string(1, Player::getPlayerChar(playerId)) + ") between (1 to " + std::to_string(this->getGrid()->getXSize()) + ") : ");

        col = ConsoleHandler::readInt();

        // Check if the column is valid
        if (col < 1 || col > this->getGrid()->getXSize())
        {
            InteractionsProvider::gameInterface->printInfo("Oops, error. Enter a column between 1 and " + std::to_string(this->getGrid()->getXSize()) + " !");
        }
        else
        {
            // Get first y position available in this col
            try
            {
                Power4Grid p4grid = static_cast<Power4Grid>(*this->getGrid());
                row = p4grid.firstRowAvailableInCol(col - 1);

                // if the previous functions has not thrown any error, we have a valid Position
                return {(col - 1), row};
            }
            catch (const std::exception &e)
            {
                InteractionsProvider::gameInterface->printError(e.what());
            }
        }
    } while (true);
}
