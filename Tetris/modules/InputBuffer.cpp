#include "tetris.h"

void clearInputBuffer()
{
    while (_kbhit())
    {
        _getch();
    }
}