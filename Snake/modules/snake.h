#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <string>

const int defaultSpeed = 500; // Max speed 900
const int speedBoostPerFood = 10;
const int snakeSize = 2;

extern std::deque<std::pair<int, int>> snake;
extern std::vector<std::vector<int>> currentMap;
extern std::vector<std::vector<int>> selectedMap;
extern const std::vector<std::vector<std::vector<int>>> sampleMap;
extern std::deque<char> inputBuffer;

/*
0 => ' ' = empty space
1 => '#' = wall
2 => '0' = snake head
3 => 'o' = snake body
4 => '*' = food
5 => 'X' = snake die
*/

extern int score;
extern int speed;
extern int tickDelay;

void filterInputBuffer();
bool isEmpty(std::pair<int, int> position);
bool isFood(std::pair<int, int> position);
void loadMap();
void createNewFood();
void spawnSnake(int size = snakeSize);
void updateCurrentMap(std::pair<int, int> &nextPosition, bool isAlive);
void displayMap(std::vector<std::vector<int>> map);
void displayMap();
void repaint();
bool moveSnake(char direction);
void play(char direction);
void selectMap();
char getInputChar();