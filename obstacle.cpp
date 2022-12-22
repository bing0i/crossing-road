#include "obstacle.h"

Shape Obstacle::getShape()
{
  return shape;
}

Car::Car() : Vehicle({
                 {0, 0, 0, 0},
                 {0, 0, 0, 0},
                 {0, 1, 1, 0},
                 {1, 1, 1, 1},
             }){};

Truck::Truck() : Vehicle({
                     {0, 0, 0},
                     {0, 0, 0},
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
                   {0, 0, 0},
                   {0, 0, 0},
               }){};

Space::Space() : Obstacle({
                     {0},
                     {0},
                     {0},
                     {0},
                 }){};