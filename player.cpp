#include "player.h"

Player::Player() : x(0), y(0), score(0) {}

void Player::move(int key)
{
  switch (key)
  {
  case 'w':
    if (y - 1 < 0)
      return;
    --y;
    break;
  case 'a':
    if (x - 1 < 0)
      return;
    --x;
    break;
  case 's':
    if (y + 1 > 100)
      return;
    ++y;
    break;
  case 'd':
    if (x + 1 > 100)
      return;
    ++x;
    break;
  }
}

int Player::getX()
{
  return x;
}

int Player::getY()
{
  return y;
}

int Player::getScore()
{
  return score;
}