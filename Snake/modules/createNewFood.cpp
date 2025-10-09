#include "snake.h"

void createNewFood()
{
    int randomY, randomX;
    while (true)
    {
        randomY = rand() % currentMap.size();
        randomX = rand() % currentMap[0].size();
        if (isEmpty({randomY, randomX}))
        {
            currentMap[randomY][randomX] = 4;
            return;
        }
    }
}