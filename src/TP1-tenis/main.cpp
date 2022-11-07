#include <iostream>

int main()
{

    std::cout << "*** TENIS ***" << std::endl;

    int scores[] = {0, 0};

    int round = 0;
    int avantage = -1;
    int winner;

    bool ended = false;

    while (!ended)
    {

        round++;

        std::cout << "\n\n**** ROUND " << round << "****" << std::endl;
        std::cout << "SCORE : " << scores[0] << " - " << scores[1] << std::endl;

        if (avantage != -1)
        {
            std::cout << "Le joueur " << (avantage + 1) << " a l'avantage !" << std::endl;
        }

        int player;
        do
        {
            std::cout << "\nQui remporte le round " << round << " ? (1 ou 2)" << std::endl;
            std::cin >> player;
        } while (player != 1 && player != 2);
        player--;

        if (scores[player] == 40)
        {
            if (scores[!player] == 40)
            {
                if (avantage == player)
                {
                    winner = player;
                    ended = true;
                }
                else if (avantage == -1)
                {
                    avantage = player;
                }
                else
                {
                    avantage = -1;
                }
            }
            else
            {
                winner = player;
                ended = true;
            }
        }
        else if (scores[player] == 30)
        {
            scores[player] = 40;
        }
        else
        {
            scores[player] += 15;
        }
    }

    std::cout << "***** MATCH TERMINE EN " << round << " ROUNDS *****" << std::endl;

    std::cout << "SCORE : " << scores[0] << " - " << scores[1] << std::endl;

    std::cout << "GAGNANT : JOUEUR " << (winner + 1) << std::endl;

    return 0;
}