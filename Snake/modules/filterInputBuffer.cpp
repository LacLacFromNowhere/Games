#include "snake.h"

void filterInputBuffer()
{
    char ch;
    while (_kbhit())
    {
        ch = _getch();

        switch (ch)
        {
        case 'w':
        case 'a':
        case 's':
        case 'd':
        case 27:
            inputBuffer.push_back(ch);
        }
    }
}