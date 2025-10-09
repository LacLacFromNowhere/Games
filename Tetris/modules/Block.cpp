#include "tetris.h"

void generateNewBlock()
{
    nextBlockCoords.clear();
    nextBlockShape = sampleBlock[rand() % sampleBlock.size()];
    
    for (int i = 0; i < nextBlockShape.size(); i++)
    {
        for (int j = 0; j < nextBlockShape[i].size(); j++)
        {
            if (nextBlockShape[i][j] == 1) 
            {
                nextBlockCoords.push_back({i - 3, spaceDistance + j});  // {Y,X}  
            }
        }
    }
}

bool isSafe(std::pair<int, int> cell)
{
    return gameBoard[cell.first][cell.second] == 0 || gameBoard[cell.first][cell.second] == 1;
}

bool canMove(char direction)
{
    switch (direction)
    {
    case 'a':
        for (auto cell : currentBlock)
        {
            if (cell.first < 0)
                return true;
            if (!isSafe({cell.first, cell.second - 1}))
            {
                return false;
            }
        }
        return true;
    case 'd':
        for (auto cell : currentBlock)
        {
            if (cell.first < 0)
                return true;
            if (!isSafe({cell.first, cell.second + 1}))
            {
                return false;
            }
        }
        return true;
    case 's':
        for (auto cell : currentBlock)
        {
            if (cell.first < 0)
                return true;
            if (!isSafe({cell.first + 1, cell.second}))
            {
                return false;
            }
        }
        return true;
    case ' ':
        for (auto cell : currentBlock)
        {
            if (cell.first < 0)
            {
                return true;
            }
            if (!isSafe({cell.first + 1, cell.second}) ||
                !isSafe({cell.first + 2, cell.second}) ||
                !isSafe({cell.first + 3, cell.second}))
            {
                return false;
            }
        }
        return true;
    default:
        return false;
    }
}

void moveCurrentBlock(char direction)
{
    if (!canMove(direction))
        return;

    int dx = 0, dy = 0;
    switch (direction)
    {
    case 'a':
        dx = -1;
        break;
    case 'd':
        dx = 1;
        break;
    case 's':
        dy = 1;
        break;
    case ' ':
        dy = 3;
        break;
    }

    for (auto &cell : currentBlock)
    {
        if (cell.first > 0) 
        {
            gameBoard[cell.first][cell.second] = 0;
        }
        cell.first += dy;
        cell.second += dx;
    }

    for (auto &cell : currentBlock)
    {
        if (cell.first > 0) 
        {
            gameBoard[cell.first][cell.second] = 1;
        }
    }
}

void rotateBlock(char direction)
{
    bool clockwise;
    if (direction == 'j')
    {
        clockwise = false;
    }
    else if (direction == 'k')
    {
        clockwise = true;
    }
    else
    {
        return;
    }

    if (currentBlock.empty())
        return;

    std::pair<int, int> pivot = currentBlock[currentBlock.size() / 2];
    std::vector<std::pair<int, int>> rotatedBlock;

    for (auto &cell : currentBlock)
    {
        std::pair<int, int> rotatedCell;

        if (clockwise)
        {
            rotatedCell.first = pivot.first - (cell.second - pivot.second);
            rotatedCell.second = pivot.second + (cell.first - pivot.first);
        }
        else
        {
            rotatedCell.first = pivot.first + (cell.second - pivot.second);
            rotatedCell.second = pivot.second - (cell.first - pivot.first);
        }

        rotatedBlock.push_back(rotatedCell);
    }

    bool canRotate = true;
    for (auto &cell : rotatedBlock)
    {
        if (!isSafe(cell))
        {
            canRotate = false;
            break;
        }
    }

    if (!canRotate)
    {
        const int kickOffsets[4] = {-1, 1, -2, 2};

        for (int offset : kickOffsets)
        {
            bool kickOK = true;
            std::vector<std::pair<int, int>> kickedBlock;

            for (auto &cell : rotatedBlock)
            {
                std::pair<int, int> newCell = {cell.first, cell.second + offset};
                if (!isSafe(newCell))
                {
                    kickOK = false;
                    break;
                }
                kickedBlock.push_back(newCell);
            }

            if (kickOK)
            {
                for (auto &cell : currentBlock)
                {
                    gameBoard[cell.first][cell.second] = 0;
                }

                currentBlock = kickedBlock;

                for (auto &cell : currentBlock)
                {
                    gameBoard[cell.first][cell.second] = 1;
                }
                return;
            }
        }

        return;
    }

    for (auto &cell : currentBlock)
    {
        gameBoard[cell.first][cell.second] = 0;
    }

    currentBlock = rotatedBlock;

    for (auto &cell : currentBlock)
    {
        gameBoard[cell.first][cell.second] = 1;
    }
}
