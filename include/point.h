#ifndef POINT_H
#define POINT_H

class Point
{
public:
  Point();
  Point(float x, float y);
  float getX();
  float getY();
  void setX(float x);
  void setY(float y);

private:
  float x, y;
};

#endif // POINT_H
