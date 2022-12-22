#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "shape.h"
#include "brush.h"

class Obstacle
{
private:
  Shape shape;

public:
  Obstacle(vector<vector<int>> s) : shape(s){};
  Shape getShape();
};

class Vehicle : public Obstacle
{
public:
  Vehicle(vector<vector<int>> s) : Obstacle(s){};
};

class Car : public Vehicle
{
public:
  Car();
};

class Truck : public Vehicle
{
public:
  Truck();
};

class Animal : public Obstacle
{
public:
  Animal(vector<vector<int>> s) : Obstacle(s){};
};

class Dinausor : public Animal
{
public:
  Dinausor();
};

class Bird : public Animal
{
public:
  Bird();
};

class Space : public Obstacle
{
public:
  Space();
};

#endif
