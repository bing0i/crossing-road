#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <thread>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include "board.h"
#include "player.h"
#include "brush.h"

using namespace std;

class Game
{
private:
  const int WIDTH = 100;
  const int HEIGHT = 5;
  bool isRunning;
  Brush brush;
  Board board;

  void fixConsoleWindow();
  void hideCursor();

  void run();

  void loadBoard(string);
  void saveBoard(string);

public:
  Game();
  void start();
  void exit(thread *);
};
#endif
