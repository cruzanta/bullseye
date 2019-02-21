#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
  virtual float getArea() = 0;
  virtual float getPerimeter() = 0;
  virtual void setFillColor(float r, float g, float b) = 0;
  virtual void draw() = 0;
};

#endif // SHAPE_H
