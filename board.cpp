#include "board.h"

void Board::drawBoard()
{
  int x = 0;
  int y = 0;
  for (int i = 0; i < board.size(); ++i)
  {
    for (int j = 0; j < board[0].size(); ++j)
    {
      Shape shape = getShape(board[i][j]);
      brush.drawShape(x, y, shape);
      x += shape.getWidth();
    }

    brush.drawLine(y + 2, 100);

    x = 0;
    y += 3;
  }
}

void Board::clearBoard()
{
  // int x = 0;
  // int y = 0;
  // Shape shape = (new Space)->getShape();
  // for (int i = 0; i < board.size(); ++i)
  // {
  //   for (int j = 0; j < board[0].size(); ++j)
  //   {
  //     if (board[i][j] == 0)
  //     {
  //       ++x;
  //       continue;
  //     }

  //     int spaceWidth = getShape(board[i][j]).getWidth();
  //     for (int k = 0; k < spaceWidth; ++k)
  //     {
  //       brush.clearShape(x + k, y, shape);
  //     }

  //     x += spaceWidth;
  //   }

  //   y += 3;
  // }

  brush.clearScreen();
}

Shape Board::getShape(int type)
{
  switch (type)
  {
  case 0:
    return (new Space)->getShape();
  case 1:
    return (new Car)->getShape();
  case 2:
    return (new Truck)->getShape();
  case 3:
    return (new Dinausor)->getShape();
  case 4:
    return (new Bird)->getShape();
  default:
    return (new Space)->getShape();
  }
}

void Board::moveObstacles()
{
  int height = board.size();
  int width = board[0].size();
  for (int i = 0; i < height; i++)
  {
    int temp = board[i][width - 1];
    for (int j = width - 1; j > 0; j--)
    {
      board[i][j] = board[i][j - 1];
    }

    board[i][0] = temp;
  }
}
