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
void reshape_func(int width, int height);
void display_func();
void keyboard_func(unsigned char c, int x, int y);
void animation_func(int val);
void update_score(float dartY);

#endif
