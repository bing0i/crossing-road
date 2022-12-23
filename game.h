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
  Brush brush;
  Board board;
  bool isRunning;
  void fixConsoleWindow();
  void hideCursor();
  void run();
  vector<vector<int>> loadBoard(string);
  void saveBoard(string);

public:
  Game();
  void start();
  void exit(thread *);
};
#endif
