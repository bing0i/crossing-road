#include "obstacle.h"

void Obstacle::move(int maxSize)
{
  isMoving = true;
  if (x + shape.getShape()[0].size() == maxSize)
  {
    x = 0;
    return;
  }

  x += 1;
}

void Obstacle::stop()
{
  isMoving = false;
}

Shape Obstacle::getShape()
{
  return shape;
}

int Obstacle::getX()
{
  return x;
}

int Obstacle::getY()
{
  return y;
}

Car::Car(int x, int y) : Vehicle(x, y, {
                                           {0, 1, 1, 0},
                                           {1, 1, 1, 1},
                                       }){};

Truck::Truck(int x, int y) : Vehicle(x, y, {
                                               {0, 1, 1},
                                               {1, 1, 1},
                                           }){};

Dinausor::Dinausor(int x, int y) : Animal(x, y, {
                                                    {0, 0, 0},
                                                    {0, 0, 1},
                                                    {0, 1, 1},
                                                    {1, 1, 0},
                                                }){};

Bird::Bird(int x, int y) : Animal(x, y, {
                                            {1, 0, 1},
                                            {0, 1, 0},
                                        }){};

Space::Space(int x, int y) : Obstacle(x, y, {
                                                {0},
                                                {0},
                                                {0},
                                                {0},
                                            }){};

Car::Car() : Vehicle({
                 {0, 1, 1, 0},
                 {1, 1, 1, 1},
             }){};

Truck::Truck() : Vehicle({
                     {0, 1, 1},
                     {1, 1, 1},
                 }){};

Dinausor::Dinausor() : Animal({
                           {0, 0, 0},
                           {0, 0, 1},
                           {0, 1, 1},
                           {1, 1, 0},
                       }){};

Bird::Bird() : Animal({
                   {1, 0, 1},
                   {0, 1, 0},
               }){};

Space::Space() : Obstacle({
                     {0},
                     {0},
                     {0},
                     {0},
                 }){};