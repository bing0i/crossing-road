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
  int score;
  Brush brush;

public:
  Player(int, int);
  void move(int);
  int getX();
  int getY();
  int getScore();
};

#endif