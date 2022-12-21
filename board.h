#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "brush.h"
#include "shape.h"
#include "obstacle.h"

class Board
{
private:
  vector<vector<int>> board = {{
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                               },
                               {
                                   1,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                                   0,
                                   1,
                               }};
  Brush brush;

public:
  void drawBoard();
  void clearBoard();
  Shape getShape(int type);
  void moveObstacles();
};

#endif