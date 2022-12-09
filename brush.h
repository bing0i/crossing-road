#ifndef BRUSH_H
#define BRUSH_H

#include <windows.h>
#include <iostream>
#include "shape.h"

using namespace std;

class Brush {
public:
	void gotoXY(int, int);
	void drawPixel(int, int, char);
	void drawShape(int, int, Shape);
	void drawLine(int, int);
	void clearShape(int x, int y, Shape s);
	void clearScreen();
};
#endif
