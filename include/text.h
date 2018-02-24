#ifndef text_h
#define text_h

#include <string>

#include "point.h"

class Text
{
public:
    Text(Point startPos, std::string text);

    Point getStartPos();
    float getStartPosX();
    float getStartPosY();

    void setStartPos(Point startPos);
    void setStartPosX(float startPosX);
    void setStartPosY(float startPosY);
    void setText(std::string text);
    void setColor(float r, float g, float b);

    void draw();

private:
    Point startPos;
    std::string text;
    float red;
    float green;
    float blue;
};

#endif
