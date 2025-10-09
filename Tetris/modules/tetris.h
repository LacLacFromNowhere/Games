#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <ctime>

const int defaultGameSpeed = 300;
const int speedBoostPerPoint = 0;
const int gameBoardWidth = 15;
const int gameBoardHeight = 15;

/*
0 => ' ' = empty space
1 => '#' = falling block
2 => '#' = placed block
3 => '=' = horizontal border
4 => '|' = vertical border
*/

extern std::vector<std::vector<std::vector<int>>> sampleBlock;
extern std::vector<std::vector<int>> gameBoard;
extern std::vector<std::pair<int, int>> currentBlock;
extern std::vector<std::vector<int>> nextBlockShape;
extern std::vector<std::pair<int, int>> nextBlockCoords;
extern int score;
extern int speed;
extern int tickDelay; 
extern int spaceDistance;

void clearInputBuffer();
void generateNewBlock();
void createGameBoard(int width = gameBoardWidth, int height = gameBoardHeight);
void displayGameBoard();
void moveCurrentBlock(char direction);
bool canMove(char direction);
void clearFullRows();
void play();
void repaint();
void rotateBlock(char direction);