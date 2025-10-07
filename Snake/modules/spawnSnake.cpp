#include "snake.h"

void spawnSnake(int size)
{
    std::pair<int, int> defaultPosition = {map.size() / 2, map[0].size() / 2};

    snake.clear();
    for (int i = 0; i < size; i++)
    {
        snake.push_back(defaultPosition);
    }

    map[defaultPosition.first][defaultPosition.second] = 2;
}