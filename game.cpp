#include "game.h"
#include <iostream>

Game::Game()
{
  // hideCursor();
  fixConsoleWindow();
  createRoads();
}

void Game::fixConsoleWindow()
{
  HWND consoleWindow = GetConsoleWindow();
  LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
  style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
  SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Game::hideCursor()
{
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}

void Game::exit(thread *t)
{
  isRunning = false;
  t->join();
}

void Game::run()
{
  Brush b;
  while (isRunning)
  {
    for (int i = 0; i < MAX_ROADS; ++i)
    {
      roads[i].start();
    }

    Sleep(500);

    for (int i = 0; i < MAX_ROADS; ++i)
    {
      roads[i].update();
    }
  }
}

void Game::start()
{
  thread t1(&Game::run, this);
  isRunning = true;
  while (true)
  {
    int temp = toupper(_getch());
    if (temp == 27)
    {
      exit(&t1);
      return;
    }
  }
}

void Game::createRoads()
{
  for (int i = 0; i < MAX_ROADS; ++i)
  {
    Road road(availableY, 5);
    roads.push_back(road);
    availableY += 3;
  }
}