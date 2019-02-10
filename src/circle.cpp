#include <math.h>
#include <GL/glut.h>

#include "../include/circle.h"

Circle::Circle(Point centerPt, float radius)
{
  setCenterPt(centerPt);
  setRadius(radius);
}

Point Circle::getCenterPt()
{
  return centerPt;
}

float Circle::getCenterPtX()
{
  return centerPt.getX();
}

float Circle::getCenterPtY()
{
  return centerPt.getY();
}

float Circle::getRadius()
{
  return radius;
}

float Circle::getDiameter()
{
  return radius * 2;
}

float Circle::getArea()
{
  return M_PI * radius * radius;
}

float Circle::getPerimeter()
{
  return 2 * M_PI * radius;
}

void Circle::setCenterPt(Point centerPt)
{
  this->centerPt = centerPt;
}

void Circle::setCenterPtX(float centerPtX)
{
  this->centerPt.setX(centerPtX);
}

void Circle::setCenterPtY(float centerPtY)
{
  this->centerPt.setY(centerPtY);
}

void Circle::setRadius(float radius)
{
  this->radius = radius;
}

void Circle::setFillColor(float r, float g, float b)
{
  red = r;
  green = g;
  blue = b;
}

void Circle::draw()
{
  float tau = 2.0 * M_PI;
  int numTriangles = 1000;
  float nextX;
  float nextY;

  glColor3f(red, green, blue);
  glEnable(GL_LINE_SMOOTH);
  glLineWidth(2);
  glBegin(GL_LINES);

  for(int i = 0; i <= numTriangles; i++)
  {
    glVertex2i(centerPt.getX(), centerPt.getY());
    nextX = centerPt.getX() + (radius * cos(i * tau / numTriangles));
    nextY = centerPt.getY() + (radius * sin(i * tau / numTriangles));
    glVertex2i(nextX, nextY);
  }
  glEnd();
}
