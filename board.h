#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "obstacle.h"
#include "shape.h"

class Board {
private:
	const int MAX_SIZE = 100;
	vector<Obstacle> obstacles;
	Shape shape;
public:
	Board(Shape);
	void updateBoard();
};

#endif