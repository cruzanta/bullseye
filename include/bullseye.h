#ifndef bullseye_h
#define bullseye_h

#include "point.h"
#include "shape.h"
#include "text.h"
#include "circle.h"
#include "rectangle.h"

// Global constants
const int ANIMATION_MSEC = 5;

// Function prototypes
void reshape(int width, int height);
void display();
void getKeyboardInput(unsigned char c, int x, int y);
void animate(int val);
void updateScore(float dartY);

#endif
