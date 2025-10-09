#include "snake.h"

void loadMap()
{
    currentMap = selectedMap;
}

void showAllMap()
{
    for (int i = 0; i < sampleMap.size(); i++)
    {
        printf("Enter %d to choose this map:\n", i + 1);
        displayMap(sampleMap[i]);
    }
}

void selectMap()
{
    system("cls");
    showAllMap();
    while (true)
    {
        printf("Enter a number to choose a map (Press ESC to cancel): ");
        std::string numStr = "";
        int num = 0;
        bool isTyping = true;
        while (isTyping)
        {
            if (_kbhit())
            {
                char ch = _getch();

                if (ch == 27)
                {
                    return;
                }

                switch (ch)
                {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                    numStr += ch;
                    printf("%c", ch);
                    break;
                case '\r':
                    num = std::stoi(numStr);
                    isTyping = false;
                    break;
                }
            }
        }

        if (num > sampleMap.size() + 1)
        {
            printf("\nInvalid number. Please try again.\n");
            continue;
        }

        selectedMap = sampleMap[num - 1];
        return;
    }
}

void displayMap(std::vector<std::vector<int>> map)
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
                printf("@ ");
                break;
            case 5:
                printf("X ");
                break;
            }
        }
        printf("\n");
    }
}

void displayMap()
{
    displayMap(currentMap);
}

void updateCurrentMap(std::pair<int, int> &nextPosition, bool isAlive)
{
    std::pair<int, int> head;

    if (isAlive)
    {
        snake.push_front(nextPosition);
        head = snake.front();

        if (!isFood(nextPosition))
        {
            std::pair<int, int> tail = snake.back();
            currentMap[tail.first][tail.second] = 0;
            snake.pop_back();
        }
        else
        {
            score++;
            speed = (speed + speedBoostPerFood) < 900 ? speed + speedBoostPerFood : 900;
            tickDelay = 1000 - speed;
            createNewFood();
        }
        currentMap[head.first][head.second] = 2;
    }
    else
    {
        head = snake.front();
        currentMap[head.first][head.second] = 5;
    }

    std::pair<int, int> body;
    for (int i = 1; i < snake.size(); i++)
    {
        body = snake[i];
        currentMap[body.first][body.second] = 3;
    }
}

bool isEmpty(std::pair<int, int> position)
{
    int cell = currentMap[position.first][position.second];
    return cell == 0;
}

bool isFood(std::pair<int, int> position)
{
    int cell = currentMap[position.first][position.second];
    return cell == 4;
}