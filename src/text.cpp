#include <GL/glut.h>

#include "../include/text.h"

Text::Text(Point startPos, std::string text)
{
  setStartPos(startPos);
  setText(text);
}

Point Text::getStartPos()
{
  return startPos;
}

float Text::getStartPosX()
{
  return startPos.getX();
}

float Text::getStartPosY()
{
  return startPos.getY();
}

void Text::setStartPos(Point startPos)
{
  this->startPos = startPos;
}

void Text::setStartPosX(float startPosX)
{
  this->startPos.setX(startPosX);
}

void Text::setStartPosY(float startPosY)
{
  this->startPos.setY(startPosY);
}

void Text::setText(std::string text)
{
  this->text = text;
}

void Text::setColor(float r, float g, float b)
{
  red = r;
  green = g;
  blue = b;
}

void Text::draw()
{
  glColor3f(red, green, blue);
  glRasterPos2i(startPos.getX(), startPos.getY());

  for (int i = 0; i < text.length(); i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
  }
}
