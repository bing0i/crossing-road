#include "brush.h"

void Brush::gotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Brush::drawPixel(int x, int y, char pixelType)
{
  gotoXY(x, y);
  cout << pixelType;
}

void Brush::drawShape(int x, int y, Shape s)
{
  vector<vector<int>> shape = s.getShape();
  gotoXY(x, y);
  for (int i = 0; i < shape.size(); i += 2)
  {
    for (int j = 0; j < shape[0].size(); ++j)
    {
      if (i + 1 < shape.size() && shape[i][j] && shape[i + 1][j])
      {
        drawPixel(x + j, y + i / 2, char(219));
      }
      else if (shape[i][j])
      {
        drawPixel(x + j, y + i / 2, char(223));
      }
      else if (i + 1 < shape.size() && shape[i + 1][j])
      {
        drawPixel(x + j, y + i / 2, char(220));
      }
    }
  }
}

void Brush::drawLine(int y, int maxSize)
{
  for (int i = 0; i < maxSize; ++i)
  {
    drawPixel(i, y, char(196));
  }
}

void Brush::clearShape(int x, int y, Shape s)
{
  vector<vector<int>> shape = s.getShape();
  gotoXY(x, y);
  for (int i = 0; i < shape.size(); i += 2)
  {
    for (int j = 0; j < shape[0].size(); ++j)
    {
      drawPixel(x + j, y + i / 2, ' ');
    }
  }
}

void Brush::clearScreen()
{
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD topLeft = {0, 0};
  cout.flush();
  if (!GetConsoleScreenBufferInfo(hOut, &csbi))
  {
    abort();
  }

  DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
  DWORD written;
  FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
  FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
  SetConsoleCursorPosition(hOut, topLeft);
}