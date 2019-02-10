#include <GL/glut.h>

#include "../include/rectangle.h"

Rectangle::Rectangle(Point lowLeftPt, float width, float height)
{
  setLowLeftPt(lowLeftPt);
  setWidth(width);
  setHeight(height);
}

Point Rectangle::getLowLeftPt()
{
  return lowLeftPt;
}

float Rectangle::getLowLeftPtX()
{
  return lowLeftPt.getX();
}

float Rectangle::getLowLeftPtY()
{
  return lowLeftPt.getY();
}

float Rectangle::getWidth()
{
  return width;
}

float Rectangle::getHeight()
{
  return height;
}

float Rectangle::getArea()
{
  return width * height;
}

float Rectangle::getPerimeter()
{
  return width * 2 + height * 2;
}

void Rectangle::setLowLeftPt(Point lowLeftPt)
{
  this->lowLeftPt = lowLeftPt;
}

void Rectangle::setLowLeftPtX(float lowLeftPtX)
{
  this->lowLeftPt.setX(lowLeftPtX);
}

void Rectangle::setLowLeftPtY(float lowLeftPtY)
{
  this->lowLeftPt.setY(lowLeftPtY);
}

void Rectangle::setWidth(float width)
{
  this->width = width;
}

void Rectangle::setHeight(float height)
{
  this->height = height;
}

void Rectangle::setFillColor(float r, float g, float b)
{
  red = r;
  green = g;
  blue = b;
}

void Rectangle::draw()
{
  glColor3f(red, green, blue);
  glRecti(lowLeftPt.getX(), lowLeftPt.getY(), width, height);
}
