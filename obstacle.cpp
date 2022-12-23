#include "obstacle.h"

Shape Object::getShape()
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

Space::Space() : Object({
                     {0},
                     {0},
                     {0},
                     {0},
                 }){};

PlayerShape::PlayerShape() : Object({
                                 {0},
                                 {0},
                                 {0},
                                 {1},
                             }){};