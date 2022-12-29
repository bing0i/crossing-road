#include "game.h"
#include <iostream>

Game::Game() : board(100, 5)
{
  hideCursor();
  fixConsoleWindow();
}

vector<vector<int>> Game::loadBoard(string path)
{
  vector<vector<int>> b;
  ifstream file(path);
  string line;
  while (getline(file, line))
  {
    vector<int> row;
    for (int i = 0; i < line.size(); ++i)
    {
      if (line[i] == ' ')
        continue;
      row.push_back(line[i] - '0');
    }
    b.push_back(row);
  }

  return b;
}

void Game::saveBoard(string path)
{
  ofstream file(path);
  for (int i = 0; i < board.getHeight(); ++i)
  {
    for (int j = 0; j < board.getWidth(); ++j)
    {
      file << board.getPosition(j, i);
      if (j != board.getWidth() - 1)
        file << " ";
    }

    file << endl;
  }
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
  int speed = board.getSpeed();
  while (isRunning)
  {
    board.drawDecorations();
    board.draw();
    if (!board.isGameOver() && !board.isPaused())
      board.moveObstacles();
    else
      continue;

    Sleep(speed);
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
      if (!board.isGameOver())
        board.movePlayer(key);
      break;
    case 'r':
      board.resetBoard();
      break;
    case 'l':
      board.setBoard(loadBoard("load.txt"));
      break;
    case 'e':
      saveBoard("save.txt");
      break;
    case 'p':
      board.pause();
      break;
    case 'c':
      board.resume();
      break;
    default:
      break;
    }
  }
}
