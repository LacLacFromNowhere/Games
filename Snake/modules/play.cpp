#include "snake.h"

void repaint()
{
    system("cls");
    displayMap();
    printf("Score: %-10dSpeed: %-10d\n", score, speed);
}

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

        char newDir = getInputChar();
        if (newDir != '\0')
        {
            if (newDir == 27)
            {
                break;
            }
            if ((newDir == 'w' && direction != 's') || newDir == 'a' && direction != 'd' || newDir == 's' && direction != 'w' || newDir == 'd' && direction != 'a')
            {
                direction = newDir;
            }
        }
    }
}