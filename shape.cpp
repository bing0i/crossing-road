#include "shape.h"

Shape::Shape(vector<vector<int>> s) : shape(s) {}

vector<std::vector<int>> Shape::getShape()
{
  return shape;
}

int Shape::getHeight()
{
  return shape.size();
}

int Shape::getWidth()
{
  return shape[0].size();
}