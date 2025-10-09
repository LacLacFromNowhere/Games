#include "tetris.h"

void repaint() {
    system("cls");
    displayGameBoard();
    Sleep(tickDelay);
}

bool isGameOver()
{
    for (auto &cell : currentBlock)
    {
        if (cell.first <= 0)
            return true;
    }

    return false;
}

void play()
{
    score = 0;
    speed = defaultGameSpeed;
    tickDelay = (1000 - speed) > 100 ? (1000 - speed) : 100;

    while (true)
    {
        currentBlock = nextBlockCoords;
        generateNewBlock();

        while (true)
        {
            repaint();

            if (_kbhit())
            {
                char direction = _getch();
                clearInputBuffer();
                if (direction == 27)
                {
                    return;
                }
                else if (direction == 'j' || direction == 'k')
                {
                    rotateBlock(direction);
                }
                else
                {
                    moveCurrentBlock(direction);
                }
            }

            if (!canMove('s'))
            {
                for (auto &cell : currentBlock)
                {
                    gameBoard[cell.first][cell.second] = 2;
                }
                break;
            }

            moveCurrentBlock('s');
        }

        if (isGameOver())
        {
            break;
        }

        clearFullRows();
    }
}