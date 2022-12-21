#include "main.h"
#include "game.h"
#include "road.h"
#include "board.h"

int main()
{
  Board board;
  while (true)
  {
    board.drawBoard();
    board.moveObstacles();
    Sleep(300);
    board.clearBoard();
  }
  return 0;
}
