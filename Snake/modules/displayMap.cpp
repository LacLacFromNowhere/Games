#include "snake.h"

void displayMap()
{
    int width = map[0].size();
    int height = map.size();
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            switch (map[h][w])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("# ");
                break;
            case 2:
                printf("0 ");
                break;
            case 3:
                printf("o ");
                break;
            case 4:
                printf("* ");
                break;
            case 5:
                printf("X ");
                break;
            }
        }
        printf("\n");
    }
}