#ifndef shape_h
#define shape_h

class Shape
{
public:
  virtual float getArea() = 0;
  virtual float getPerimeter() = 0;
  virtual void setFillColor(float r, float g, float b) = 0;
  virtual void draw() = 0;
};

#endif
