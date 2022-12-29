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
  const int MAX_LEVEL = 5;
  const int SPEED = 300;

  vector<vector<int>> board;
  string status = "Running";
  int level = 1;

  Brush brush;
  Player player;

  Shape getShape(int);
  int getRandomNumber(int, int);

  bool isCollied(int, int);
  bool isCompleteShape(int, int, int);

  void increaseLevel();
  void generateBoard();

public:
  Board(vector<vector<int>>);
  Board(int, int);
  void setBoard(vector<vector<int>>);
  int getPosition(int, int);
  int getWidth();
  int getHeight();
  int getSpeed();
  string getStatus();

  void draw();
  void drawDecorations();

  void moveObstacles();
  void movePlayer(char);

  void resetBoard();

  void pause();
  void resume();

  bool isGameOver();
  bool isPaused();
};

#endif