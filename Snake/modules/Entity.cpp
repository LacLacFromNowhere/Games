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

bool moveSnake(char direction)
{
    std::pair<int, int> head = snake[0];
    std::pair<int, int> nextPosition;
    switch (direction)
    {
    case 'w':
        nextPosition = {head.first - 1, head.second};
        break;
    case 'a':
        nextPosition = {head.first, head.second - 1};
        break;
    case 's':
        nextPosition = {head.first + 1, head.second};
        break;
    case 'd':
        nextPosition = {head.first, head.second + 1};
        break;
    }
    if (isEmpty(nextPosition) || isFood(nextPosition))
    {
        updateCurrentMap(nextPosition, true);
        repaint();
        return true;
    }

    updateCurrentMap(nextPosition, false);
    repaint();
    return false;
}

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