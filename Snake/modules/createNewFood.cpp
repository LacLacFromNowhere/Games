#include "snake.h"

void createNewFood() 
{
    while (true)
    {
        int randomY = rand() % map.size();
        int randomX = rand() % map[0].size();
        if (isEmpty({randomY,randomX})) {
            map[randomY][randomX] = 4;
            return;
        }
    }
}