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