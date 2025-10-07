#include "snake.h"

void generateMap(int width, int height, int mode)
{
    map.clear();
    switch (mode)
    {
    case 0: // defaut mode
        std::vector<int> topAndBottomRow(width, 1);
        map.push_back(topAndBottomRow);
        for (int i = 1; i < height - 1; i++)
        {
            std::vector<int> row(width, 0);
            row.front() = 1;
            row.back() = 1;
            map.push_back(row);
        }
        map.push_back(topAndBottomRow);
        break;
    }
}