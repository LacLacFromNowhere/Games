#include "tetris.h"

void createGameBoard(int width, int height)
{
    gameBoard.clear();
    std::vector<int> topAndBottomRow(width,3);
    std::vector<int> bodyRow(width,0);
    bodyRow.front() = 4;
    bodyRow.back() = 4;
    
    gameBoard.push_back(topAndBottomRow);
    for (int i = 1; i < height - 1; i++)
    {
        gameBoard.push_back(bodyRow);
    }
    gameBoard.push_back(topAndBottomRow);

    int boardWidth = gameBoard[0].size();
    spaceDistance = (boardWidth / 2) - (2 - (boardWidth % 2));
}

void displayGameBoard()
{
    printf("Next block:\n");
    for (int i = 0; i < nextBlockShape.size(); i++)
    {
        int boardWidth = gameBoard[0].size();
        int spaceDistance = (boardWidth / 2) - (2 - (boardWidth % 2));
        while(spaceDistance--){
            printf(" ");
        }
        for (int j = 0; j < nextBlockShape[i].size(); j++)
        {
            if(nextBlockShape[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < gameBoard.size(); i++)
    {
        for (int j = 0; j < gameBoard[i].size(); j++)
        {
            switch (gameBoard[i][j])
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("#");
                break;
            case 2:
                printf("@");
                break;
            case 3:
                printf("=");
                break;
            case 4:
                printf("|");
                break;
            }
        }
        printf("\n");
    }

    printf("Score: %-10dSpeed: %-10d\n",score,speed);
}

bool isFullRow(std::vector<int> row)
{
    for (int i = 1; i < row.size() - 1; i++)
    {
        if (!(row[i] == 2))
            return false;
    }

    return true;
}

void clearFullRows()
{
    printf("1");
    for (int i = 1; i < gameBoard.size() - 1; i++)
    {
        if (isFullRow(gameBoard[i])) {
            score += gameBoard[i].size() - 2;
            speed = defaultGameSpeed + score * speedBoostPerPoint;
            tickDelay = (1000 - speed) > 100 ? (1000 - speed) : 100;

            std::vector<int> newRow(gameBoard[i].size(),0);
            newRow.front()=4;
            newRow.back()=4;

            gameBoard.erase(gameBoard.begin() + i);
            gameBoard.insert(gameBoard.begin() + 1,newRow);
            i--;
        }
    }
}