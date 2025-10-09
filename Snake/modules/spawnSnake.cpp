#include "snake.h"

void spawnSnake(int size)
{
    int randomY, randomX;
    std::pair<int, int> defaultPosition;

    while (true)
    {
        randomY = rand() % currentMap.size();
        randomX = rand() % currentMap[0].size();
        if (isEmpty({randomY, randomX}))
        {
            defaultPosition = {randomY, randomX};

            snake.clear();
            for (int i = 0; i < size; i++)
            {
                snake.push_back(defaultPosition);
            }

            currentMap[defaultPosition.first][defaultPosition.second] = 2;

            return;
        }
    }
}