#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "shape.h"
#include "brush.h"

class Obstacle {
private:
	int x;
	int y;
	bool isMoving = false;
	Shape shape;
public:
	Obstacle(int coordX, int coordY, vector<vector<int>> s) : shape(s), x(coordX), y(coordY) {};
	void move(int);
	void stop();
	Shape getShape();
	int getX();
	int getY();
};

class Vehicle : public Obstacle {
public:
	Vehicle(int x, int y, vector<vector<int>> s) : Obstacle(x, y, s) {};
};

class Car : public Vehicle {
public:
	Car(int, int);
};

class Truck : public Vehicle {
public:
	Truck(int, int);
};

class Animal : public Obstacle {
public:
	Animal(int x, int y, vector<vector<int>> s) : Obstacle(x, y, s) {};
};

class Dinausor : public Animal {
public:
	Dinausor(int, int);
};

class Bird : public Animal {
public:
	Bird(int, int);
};

class Space : public Obstacle {
public:
	Space(int, int);
};

#endif
