#include "board.h"

Board::Board(vector<vector<int>> b) : board(b), player(getWidth(), getHeight()) {}

Board::Board(int width, int height) : board(height, vector<int>(width, 0)), player(width, height)
{
  player.setXY(width / 2, 0);
  generateBoard();
}

int Board::getPosition(int x, int y)
{
  return board[y][x];
}

void Board::setBoard(vector<vector<int>> b)
{
  board = b;
  for (int i = 0; i < getHeight(); ++i)
  {
    for (int j = 0; j < getWidth(); ++j)
    {
      if (board[i][j] == -1)
      {
        player.setXY(j, i);
        return;
      }
    }
  }
}

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
        brush.changeColor(2);

      Shape shape = getShape(board[i][j]);
      int shapeWidth = shape.getWidth();
      if (!isCompleteShape(i, j, shapeWidth))
      {
        ++x;
        continue;
      }

      brush.drawShape(x, y, shape);
      x += shapeWidth;
      j += shapeWidth - 1;

      if (board[i][j] == -1)
        brush.changeColor(15);
    }

    x = START_X;
    y += GAP;
  }
}

bool Board::isCompleteShape(int i, int j, int width)
{
  int count = 0;
  for (int k = 0; k < width; ++k)
  {
    if (j + k >= getWidth())
      return false;
    if (board[i][j] != board[i][j + k])
      return false;
    ++count;
  }

  return count == width;
}

Shape Board::getShape(int type)
{
  switch (type)
  {
  case -1:
    return (new PlayerShape)->getShape();
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
  int height = getHeight();
  int width = getWidth();
  for (int i = 0; i < height; ++i)
  {
    int lastElement = board[i][width - 1];
    for (int j = width; j > 0; j--)
    {
      board[i][j] = board[i][j - 1];
    }

    board[i][0] = lastElement;
  }

  int x = player.getX();
  int y = player.getY();
  if (isCollied(x, y))
  {
    status = "Game Over";
    return;
  }

  board[y][x] = -1;
  board[y][x + 1] = 0;
  return;
}

bool Board::isCollied(int x, int y)
{
  return board[y][x] != 0;
}

void Board::movePlayer(char key)
{
  int oldX = player.getX();
  int oldY = player.getY();

  if (key == 's' && oldY == getHeight() - 1)
  {
    player.setXY(oldX, 0);
    player.increaseScore();
    increaseLevel();
    return;
  }

  player.move(key);
  int x = player.getX();
  int y = player.getY();

  if (isCollied(x, y))
  {
    status = "Game Over";
    return;
  }

  board[oldY][oldX] = 0;
  board[y][x] = -1;

  if (key == 's')
    player.increaseScore();

  return;
}

void Board::drawDecorations()
{
  brush.gotoXY(START_X - 1, START_Y - 1);
  cout << char(201);
  for (int i = 0; i < getWidth(); ++i)
    cout << char(205);
  cout << char(187);

  for (int i = START_Y; i < 4 * getHeight() - 1; ++i)
  {
    brush.gotoXY(START_X - 1, i);
    cout << char(186);
  }

  for (int i = START_Y; i < 4 * getHeight() - 1; ++i)
  {
    brush.gotoXY(START_X + getWidth(), i);
    cout << char(186);
  }

  brush.gotoXY(START_X - 1, 4 * getHeight() - 1);
  cout << char(200);
  for (int i = 0; i < getWidth(); ++i)
    cout << char(205);
  cout << char(188);

  for (int i = 1; i <= getHeight(); ++i)
  {
    brush.gotoXY(START_X, 3 * i + START_Y - 1);
    for (int j = 0; j < getWidth(); ++j)
      cout << char(205);
  }

  brush.gotoXY(START_X + 5, 22);
  brush.changeColor(3);
  cout << "Status: " << status;
  brush.gotoXY(START_X + 5, 23);
  cout << "Score: " << player.getScore() << " - Level: " << level;
  brush.changeColor(15);

  brush.gotoXY(START_X + 5, 24);
  cout << "Press [W] to move up";
  brush.gotoXY(START_X + 5, 25);
  cout << "Press [S] to move down";
  brush.gotoXY(START_X + 5, 26);
  cout << "Press [A] to move left";
  brush.gotoXY(START_X + 5, 27);
  cout << "Press [D] to move right";

  brush.gotoXY(75, 22);
  cout << "Press [R] to restart";
  brush.gotoXY(75, 23);
  cout << "Press [L] to load (.\\load.txt)";
  brush.gotoXY(75, 24);
  cout << "Press [E] to save (.\\save.txt)";
  brush.gotoXY(75, 25);
  cout << "Press [P] to pause";
  brush.gotoXY(75, 26);
  cout << "Press [C] to continue";
  brush.gotoXY(75, 27);
  cout << "Press [Q] to quit";
}

int Board::getRandomNumber(int start, int end)
{
  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<mt19937::result_type> dist6(start, end);
  return dist6(rng);
}

void Board::generateBoard()
{
  int height = getHeight();
  int width = getWidth();
  for (int i = 0; i < width; ++i)
  {
    board[0][i] = 0;
  }

  player.setXY(player.getX(), 0);
  board[0][player.getX()] = -1;
  for (int i = 1; i < height; ++i)
  {
    int type = getRandomNumber(1, 4);
    for (int j = 0; j < width; ++j)
    {
      int shapeWidth = getShape(type).getWidth();
      for (int k = 0; k < shapeWidth; ++k)
      {
        board[i][j] = type;
        ++j;
      }

      int spaces = getRandomNumber(10 / level, 20 / level);
      for (int k = 0; k < spaces; ++k)
      {
        board[i][j] = 0;
        ++j;
      }
    }
  }
}

int Board::getSpeed()
{
  return SPEED;
}

void Board::increaseLevel()
{
  if (level == MAX_LEVEL)
  {
    level = 1;
  }
  else
  {
    ++level;
  }

  generateBoard();
}

void Board::resetBoard()
{
  player.setXY(getWidth() / 2, 0);
  player.resetScore();

  level = 1;
  status = "Running";
  generateBoard();
}

bool Board::isGameOver()
{
  return status == "Game Over";
}

string Board::getStatus()
{
  return status;
}

void Board::resume()
{
  status = "Running";
}

void Board::pause()
{
  status = "Paused";
}

bool Board::isPaused()
{
  return status == "Paused";
}

int Board::getLevel()
{
  return level;
}

void Board::setLevel(int level)
{
  this->level = level;
}

int Board::getScore()
{
  return player.getScore();
}

void Board::setScore(int level)
{
  player.setScore(level);
}