#include "power4PositionRequester.hpp"

Position Power4PositionRequester::askForPosition(const PlayerId playerId) const
{
    int col, row;

    do
    {
        ConsoleHandler::printLine("Dans quelle colonne souhaitez vous jouer ? (1-" + std::to_string(this->getGrid().getXSize()) + ")");

        col = ConsoleHandler::readInt();

        // Check if the column is valid
        if (col < 1 || col > this->getGrid().getXSize())
        {
            ConsoleHandler::printLine("Veuillez entrer une colonne entre 1 et " + std::to_string(this->getGrid().getXSize()) + ".");
        }
        else
        {
            // Get first y position available in this col
            try
            {
                Power4Grid p4grid = static_cast<Power4Grid>(this->getGrid());
                row = p4grid.firstRowAvailableInCol(col - 1);

                // if the previous functions has not thrown any error, we have a valid Position
                return {(col - 1), row};
            }
            catch (const std::exception &e)
            {
                ConsoleHandler::printLine(e.what());
            }
        }
    } while (true);
}
