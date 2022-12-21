#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <thread>
#include <conio.h>
#include <vector>
#include "road.h"

using namespace std;

class Game
{
private:
  const int MAX_ROADS = 6;
  vector<Road> roads;
  bool isRunning;
  int availableY = 0;
  void fixConsoleWindow();
  void hideCursor();
  void run();

public:
  Game();
  void start();
  void exit(thread *);
  void createRoads();
};
#endif
