#ifndef PLAYER_H
#define PLAYER_H

#include "brush.h"

class Player
{
private:
  int x;
  int y;
  int score;
  Brush brush;

public:
  Player();
  void move(int);
  int getX();
  int getY();
  int getScore();
};

#endif