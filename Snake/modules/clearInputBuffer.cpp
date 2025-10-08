#include "snake.h"

void clearInputBuffer()
{
    while (_kbhit)
    {
        _getch;
    }
}