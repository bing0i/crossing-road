#ifndef PLAYER_H
#define PLAYER_H

#include "brush.h"

class Player
{
private:
  int width;
  int height;
  int x;
  int y;
  int score = 0;
  Brush brush;

public:
  Player(int, int);
  void increaseScore();
  void resetScore();
  void setXY(int, int);
  int getScore();
  int getX();
  int getY();

  void move(int);
};

#endif