#include "snake.h"

bool isEmpty(std::pair<int, int> position)
{
    int cell = map[position.first][position.second];
    return cell == 0;
}

bool isFood(std::pair<int, int> position)
{
    int cell = map[position.first][position.second];
    return cell == 4;
}