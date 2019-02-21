#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "shape.h"

class Circle : public Shape
{
public:
  Circle(Point centerPt, float radius);
  Point getCenterPt();
  float getCenterPtX();
  float getCenterPtY();
  float getRadius();
  float getDiameter();
  float getArea();
  float getPerimeter();
  void setCenterPt(Point centerPt);
  void setCenterPtX(float centerPtX);
  void setCenterPtY(float centerPtY);
  void setRadius(float radius);
  void setFillColor(float r, float g, float b);
  void draw();

private:
  Point centerPt;
  float radius;
  float red;
  float green;
  float blue;
};

#endif // CIRCLE_H
