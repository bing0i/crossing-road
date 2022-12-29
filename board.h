#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <random>
#include "brush.h"
#include "player.h"
#include "obstacle.h"

class Board
{
private:
  const int START_X = 10;
  const int START_Y = 5;
  const int GAP = 3;

  vector<vector<int>> board;
  string status = "playing";
  int level = 1;

  Brush brush;
  Player player;

  Shape getShape(int);
  int getRandomNumber(int, int);

  bool isCollied(int, int);
  bool isCompleteShape(int, int, int);

public:
  Board(vector<vector<int>>);
  Board(int, int);
  void setBoard(vector<vector<int>>);
  int getPosition(int, int);
  int getWidth();
  int getHeight();
  int getSpeed();

  void draw();
  void drawDecorations();

  bool moveObstacles();
  bool movePlayer(char);

  void generateBoard();

  void increaseLevel();
};

#endif