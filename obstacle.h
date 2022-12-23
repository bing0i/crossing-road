#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "shape.h"
#include "brush.h"

class Object
{
private:
  Shape shape;

public:
  Object(vector<vector<int>> s) : shape(s){};
  Shape getShape();
};

class Vehicle : public Object
{
public:
  Vehicle(vector<vector<int>> s) : Object(s){};
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

class Animal : public Object
{
public:
  Animal(vector<vector<int>> s) : Object(s){};
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

class Space : public Object
{
public:
  Space();
};

class PlayerShape : public Object
{
public:
  PlayerShape();
};

#endif
