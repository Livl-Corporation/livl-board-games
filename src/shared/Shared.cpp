#include "Shared.h"

namespace Shared
{
    int randomInt(int min, int max)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(min, max);

        return uni(rng);
    }

}
