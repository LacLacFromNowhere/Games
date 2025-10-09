#include "snake.h"

void updateCurrentMap(std::pair<int, int> &nextPosition, bool isAlive)
{
    std::pair<int, int> head;

    if (isAlive)
    {
        snake.push_front(nextPosition);
        head = snake.front();

        if (!isFood(nextPosition))
        {
            std::pair<int, int> tail = snake.back();
            currentMap[tail.first][tail.second] = 0;
            snake.pop_back();
        }
        else
        {
            score++;
            speed = (speed + speedBoostPerFood) < 900 ? speed + speedBoostPerFood : 900;
            tickDelay = 1000 - speed;
            createNewFood();
        }
        currentMap[head.first][head.second] = 2;
    }
    else
    {
        head = snake.front();
        currentMap[head.first][head.second] = 5;
    }

    std::pair<int, int> body;
    for (int i = 1; i < snake.size(); i++)
    {
        body = snake[i];
        currentMap[body.first][body.second] = 3;
    }
}