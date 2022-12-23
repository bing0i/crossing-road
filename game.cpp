#include "game.h"
#include <iostream>

Game::Game()
{
  hideCursor();
  fixConsoleWindow();
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
  while (isRunning)
  {
    board.drawDecorations();
    board.draw();
    Sleep(1000);
    if (!board.moveObstacles())
      return;

    brush.clearScreen();
  }
}

void Game::start()
{
  thread t1(&Game::run, this);
  isRunning = true;
  while (true)
  {
    int key = tolower(_getch());
    switch (key)
    {
    case 'q':
      exit(&t1);
      return;
    case 'w':
    case 'a':
    case 's':
    case 'd':
      if (!board.movePlayer(key))
      {
        _getch();
        exit(&t1);
        return;
      }
      break;
    default:
      break;
    }
  }
}
