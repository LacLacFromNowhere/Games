#include "snake.h"

void createMap(int width, int height)
{
    map.clear();

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
}

void createMap(std::vector<std::vector<int>> newMap) {
    map = newMap;
}