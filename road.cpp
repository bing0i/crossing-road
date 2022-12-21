#include "road.h"

Road::Road(int start, int level) : startY(start), endY(start + 3)
{
  int quantity = 10;
  generateObstacles(quantity);
}

int Road::getRandomNumber(int start, int end)
{
  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<mt19937::result_type> dist6(start, end);
  return dist6(rng);
}

vector<int> Road::generateObstacleTypes(int quantity)
{
  int objectType = getRandomNumber(1, 4);
  int randomSpaces = getRandomNumber(0, 5);
  vector<int> obstacleTypes;

  for (int j = 0; j < randomSpaces; ++j)
  {
    obstacleTypes.push_back(0);
  }

  for (int i = 1; i <= quantity; ++i)
  {
    obstacleTypes.push_back(objectType);
    randomSpaces = getRandomNumber(2, 5);
    for (int j = 0; j < randomSpaces; ++j)
    {
      obstacleTypes.push_back(0);
    }
  }

  return obstacleTypes;
}

void Road::generateObstacles(int quantity)
{
  vector<int> obstacleTypes = generateObstacleTypes(quantity);
  for (int i = 0; i < obstacleTypes.size(); ++i)
  {
    switch (obstacleTypes[i])
    {
    case 0:
    {
      Space space(availableX, startY + 1);
      obstacles.push_back(space);
      availableX += 2;
      break;
    }
    case 1:
    {
      Car car(availableX, endY - 1);
      obstacles.push_back(car);
      availableX += 2;
      break;
    }
    case 2:
    {
      Truck truck(availableX, endY - 1);
      obstacles.push_back(truck);
      availableX += 2;
      break;
    }
    case 3:
    {
      Dinausor dinausor(availableX, endY - 2);
      obstacles.push_back(dinausor);
      availableX += 2;

      break;
    }
    case 4:
    {
      Bird bird(availableX, endY - 2);
      obstacles.push_back(bird);
      availableX += 2;
      break;
    }
    }
  }
}

void Road::start()
{
  isRunning = true;
  brush.drawLine(startY, MAX_SIZE);
  brush.drawLine(endY, MAX_SIZE);
  for (int i = 0; i < obstacles.size(); ++i)
  {
    brush.drawShape(obstacles[i].getX(), obstacles[i].getY(), obstacles[i].getShape());
  }
}

void Road::update()
{
  for (int i = 0; i < obstacles.size(); ++i)
  {
    // brush.clearShape(obstacles[i].getX(), obstacles[i].getY(), obstacles[i].getShape());
    obstacles[i].move(MAX_SIZE);
  }
}

void Road::stop()
{
  isRunning = false;
}