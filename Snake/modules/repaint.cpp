#include "snake.h"

void repaint()
{
    system("cls");
    displayMap();
    printf("Score: %-10dSpeed: %-10d\n", score, speed);
}