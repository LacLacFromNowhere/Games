#include "snake.h"

char getInputChar()
{
    if (!inputBuffer.empty())
    {
        char ch = inputBuffer.front();
        inputBuffer.pop_front();
        return ch;
    }

    if (_kbhit())
    {
        filterInputBuffer();
        if (!inputBuffer.empty())
        {
            char ch = inputBuffer.front();
            inputBuffer.pop_front();
            return ch;
        }
    }

    return '\0';
}

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