#include "snake.h"

void play(char direction)
{
    speed = defaultSpeed;
    score = 0;
    bool alive = true;

    while (alive)
    {
        Sleep(tickDelay);

        alive = moveSnake(direction);

        if (!alive)
        {
            break;
        }

        if (_kbhit())

        {
            char newDir = _getch();
            clearInputBuffer();
            if (newDir == 27)
            {

                break;
            }
            if ((newDir == 'w' && direction != 's') 
            || newDir == 'a' && direction != 'd' 
            || newDir == 's' && direction != 'w' 
            || newDir == 'd' && direction != 'a')
            {
                direction = newDir;
            }
        }
    }
}