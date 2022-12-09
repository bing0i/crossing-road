#ifndef ROAD_H
#define ROAD_H

#include <vector>
#include <random>
#include "obstacle.h"
#include "brush.h"

using namespace std;

class Road {
private:
	const int MAX_SIZE = 100;
	bool isRunning = false;
	int startY;
	int endY;
	int availableX = 0;
	Brush brush;
	vector<Obstacle> obstacles;
	int getRandomNumber(int, int);
	vector<int> generateObstacleTypes(int quantity);
	void generateObstacles(int);
public:
	Road(int, int);
	void start();
	void update();
	void stop();
};

#endif