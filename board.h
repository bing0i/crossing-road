#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "brush.h"
#include "player.h"
#include "obstacle.h"

class Board
{
private:
  const int START_X = 10;
  const int START_Y = 5;
  const int GAP = 3;
  vector<vector<int>> board = {
      {
          -1,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
          0,
      },
      {
          1,
          1,
          1,
          1,
          0,
          0,
          0,
          0,
          0,
          1,
          1,
          1,
          1,
          0,
          1,
          1,
          1,
          1,
          0,
          0,
          1,
          1,
          1,
          1,
          0,
      },
      {
          2,
          2,
          2,
          0,
          0,
          0,
          0,
          0,
          0,
          2,
          2,
          2,
          0,
          0,
          2,
          2,
          3,
          0,
          0,
          0,
          1,
          1,
          1,
          1,
          0,
      },
      {
          3,
          3,
          3,
          0,
          0,
          0,
          0,
          0,
          0,
          3,
          3,
          3,
          0,
          0,
          3,
          3,
          3,
          0,
          0,
          0,
          1,
          1,
          1,
          1,
          0,
      },
      {
          4,
          4,
          4,
          0,
          0,
          0,
          0,
          0,
          0,
          4,
          4,
          4,
          0,
          0,
          4,
          4,
          4,
          0,
          0,
          0,
          1,
          1,
          1,
          1,
          0,
      },
  };
  Brush brush;
  Shape getShape(int);
  Player player;
  bool isCollied(int, int);
  bool isCompleteShape(int, int, int);

public:
  Board();
  void draw();
  bool moveObstacles();
  int getWidth();
  int getHeight();
  bool movePlayer(char);
  void drawDecorations();
};

#endif