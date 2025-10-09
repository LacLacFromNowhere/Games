#pragma once 
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

const int defaultSpeed = 500; // Max speed 900
const int speedBoostPerFood = 10;
const int mapWidth = 21;
const int mapHeight = 11;
const int snakeSize = 2;

extern std::deque<std::pair<int, int>> snake;
extern std::vector<std::vector<int>> map;

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

void clearInputBuffer();
bool isEmpty(std::pair<int, int> position);
bool isFood(std::pair<int, int> position);
void createEmptyMap(int width = mapWidth, int height = mapHeight);
void createMap(std::vector<std::vector<int>> newMap);
void createNewFood();
void spawnSnake(int size = snakeSize);
void updateMap(std::pair<int, int>& nextPosition, bool isAlive);
void displayMap();
void repaint();
bool moveSnake(char direction);
void play(char direction);