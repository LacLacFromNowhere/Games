#include "modules/tetris.h"

std::vector<std::vector<std::vector<int>>> sampleBlock = {
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
    },
};

std::vector<std::vector<int>> gameBoard;
std::vector<std::pair<int, int>> currentBlock;
std::vector<std::vector<int>> nextBlockShape;
std::vector<std::pair<int, int>> nextBlockCoords;

int score;
int speed;
int tickDelay;
int spaceDistance;

int main()
{
    srand(time(0));

    createGameBoard();
    generateNewBlock();
    displayGameBoard();

    printf("Press H to open the guide.\n");
    printf("Press SPACE to start (ESC to quit).\n");
    while (true)
    {
        if (_kbhit())
        {
            char ch = _getch();
            clearInputBuffer();
            if (ch == 27)
            {
                return 0;
            }
            if (ch == ' ')
            {
                break;
            }
            if (ch == 'h')
            {
                printf("A / D : Move block left / right\n");
                printf("  S   : Speed up falling\n");
                printf("J / K : Rotate counterclockwise / clockwise\n");
                printf("Press SPACE to start (ESC to quit).\n");
            }
        }
    }

    while (true)
    {
        system("cls");

        play();
        printf("Game over. Press R to restart (ESC to quit).\n");

        while (true)
        {
            if (_kbhit())
            {
                char ch = _getch();
                clearInputBuffer();
                if (ch == 'r')
                {
                    createGameBoard();
                    break;
                }
                if (ch == 27)
                {
                    return 0;
                }
            }
        }
    }
}
