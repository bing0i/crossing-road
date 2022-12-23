#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
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
  Brush brush;
  Shape getShape(int);
  Player player;
  string status = "playing";
  int level = 1;
  bool isCollied(int, int);
  bool isCompleteShape(int, int, int);

public:
  Board(vector<vector<int>>);
  int getPosition(int, int);
  void setBoard(vector<vector<int>>);
  void draw();
  bool moveObstacles();
  int getWidth();
  int getHeight();
  bool movePlayer(char);
  void drawDecorations();
};

#endif