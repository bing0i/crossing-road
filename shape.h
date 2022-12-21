#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

using namespace std;

class Shape
{
private:
  vector<vector<int>> shape;

public:
  Shape(vector<vector<int>> shape);
  vector<std::vector<int>> getShape();
  int getHeight();
  int getWidth();
};

#endif
