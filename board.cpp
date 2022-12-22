#include "board.h"

int Board::getWidth()
{
  return board[0].size();
}

int Board::getHeight()
{
  return board.size();
}

void Board::draw()
{
  int x = START_X;
  int y = START_Y;
  for (int i = 0; i < getHeight(); ++i)
  {
    for (int j = 0; j < getWidth(); ++j)
    {
      if (board[i][j] == -1)
      {
        brush.drawPixel(x, y, 'Y');
        x += 1;
        continue;
      }

      Shape shape = getShape(board[i][j]);
      brush.drawShape(x, y, shape);
      x += shape.getWidth();
      j += shape.getWidth() - 1;
    }

    x = START_X;
    y += GAP;
  }
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

bool Board::moveObstacles()
{
  int height = getHeight();
  int width = getWidth();
  bool isPlayerOnLastCol = false;
  for (int i = 0; i < height; ++i)
  {
    bool isPlayerOnLastCol = board[i][width - 1] == -1;
    int lastCol = isPlayerOnLastCol ? width - 2 : width - 1;
    int lastElement = board[i][lastCol];
    for (int j = lastCol; j > 0; j--)
    {
      if (!isPlayerOnLastCol && board[i][j - 1] == -1)
        movePlayer('d');

      if (board[i][j] == -1)
        continue;

      board[i][j] = board[i][j - 1];
    }

    board[i][0] = lastElement;
  }

  return isPlayerOnLastCol ? true : movePlayer('a');
}

bool Board::isCollied(int x, int y)
{
  return board[y][x] != 0;
}

bool Board::movePlayer(char key)
{
  int oldX = player.getX();
  int oldY = player.getY();

  player.move(key);
  int x = player.getX();
  int y = player.getY();

  if (!isCollied(x, y))
  {
    board[oldY][oldX] = 0;
    board[y][x] = -1;
    return true;
  }

  return false;
}

void Board::drawDecorations()
{
  brush.gotoXY(0, 0);
  cout << "(C)ontinue Sav(e) (P)ause (R)estart (Q)uit" << endl;
  cout << "Score: " << player.getScore();

  brush.gotoXY(START_X - 1, START_Y - 1);

  cout << char(201);
  for (int i = 0; i < getWidth() + 3; ++i)
    cout << char(205);
  cout << char(187);

  for (int i = START_Y; i < 4 * getHeight() - 1; ++i)
  {
    brush.gotoXY(START_X - 1, i);
    cout << char(186);
  }

  for (int i = START_Y; i < 4 * getHeight() - 1; ++i)
  {
    brush.gotoXY(START_X + getWidth() + 3, i);
    cout << char(186);
  }

  brush.gotoXY(START_X - 1, 4 * getHeight() - 1);
  cout << char(200);
  for (int i = 0; i < getWidth() + 3; ++i)
    cout << char(205);
  cout << char(188);
}