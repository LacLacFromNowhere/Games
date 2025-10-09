#include "modules/snake.h"

std::deque<std::pair<int, int>> snake;
std::vector<std::vector<int>> map;
int score = 0;
int speed = defaultSpeed;
int tickDelay = (1000 - speed) > 100 ? (1000 - speed) : 100; 

std::vector<std::vector<std::vector<int>>> sampleMap = {
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    }
};

int main()
{
    srand(time(0));
    
    do
    {
        system("cls");
        createEmptyMap();
        spawnSnake();
        createNewFood();
        displayMap();
        printf("Score: %-10dSpeed: %-10d\n", score, speed);
        printf("Press W A S D to move (ESC to quit).\n");

        char direction;
        while (true)
        {
            if (_kbhit())
            {
                direction = _getch();
                clearInputBuffer();
                if (direction == 27)
                    return 0;
                if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd')
                    break;
            }
        }

        play(direction);

        printf("Game over. Press R to restart (ESC to quit).\n");
        do
        {
            if (_kbhit())
            {
                char ch = _getch();
                clearInputBuffer();
                if (ch == 'r')
                {
                    break;
                }
                else
                {
                    if (ch == 27)
                    {
                        return 0;
                    }
                }
            }
        } while (true);
    } while (true);
    system("cls");
}
