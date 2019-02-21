#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include "shape.h"

class Rectangle : public Shape
{
public:
  Rectangle(Point lowLeftPt, float width, float height);
  Point getLowLeftPt();
  float getLowLeftPtX();
  float getLowLeftPtY();
  float getWidth();
  float getHeight();
  float getArea();
  float getPerimeter();
  void setLowLeftPt(Point lowLeftPt);
  void setLowLeftPtX(float lowLeftPtX);
  void setLowLeftPtY(float lowLeftPtY);
  void setWidth(float width);
  void setHeight(float height);
  void setFillColor(float r, float g, float b);
  void draw();

private:
  Point lowLeftPt;
  float width;
  float height;
  float red;
  float green;
  float blue;
};

#endif // RECTANGLE_H
