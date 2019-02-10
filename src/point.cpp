#include "../include/point.h"

Point::Point()
{
  setX(0);
  setY(0);
}

Point::Point(float x, float y)
{
  setX(x);
  setY(y);
}

float Point::getX()
{
  return x;
}

float Point::getY()
{
  return y;
}

void Point::setX(float x)
{
  this->x = x;
}

void Point::setY(float y)
{
  this->y = y;
}
