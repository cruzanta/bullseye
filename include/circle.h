#ifndef circle_h
#define circle_h

#include "shape.h"
#include "point.h"

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

#endif
