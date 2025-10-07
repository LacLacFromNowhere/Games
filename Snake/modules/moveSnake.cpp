#include "snake.h"

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
        updateMap(nextPosition, true);
        repaint();
        return true;
    }
    
    updateMap(nextPosition, false);
    repaint();
    return false;
}