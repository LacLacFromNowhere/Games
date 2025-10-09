#include "snake.h"

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