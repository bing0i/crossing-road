#include "shape.h"

Shape::Shape(vector<vector<int>> s) : shape(s) {}

vector<std::vector<int>> Shape::getShape() {
	return shape;
}