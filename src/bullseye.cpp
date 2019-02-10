#include <GL/glut.h>

#include "../include/bullseye.h"
#include "../include/point.h"
#include "../include/text.h"
#include "../include/circle.h"
#include "../include/rectangle.h"

// Global variables
int roundNum = 0;
int score = 0;
int powerBarSpeed = 3;
bool showInstructions = true;
bool powerBarActive = false;
bool powerBarUp = false;
bool dartActive = false;
bool throwActive = false;

// Points
Point startInstructionPt(25, 870);
Point stopInstructionPt(25, 850);
Point throwInstructionPt(25, 830);
Point quitInstructionPt(25, 810);
Point gameRoundPt(380, 870);
Point gameScorePt(384, 850);
Point targetCenterPt(252, 670);
Point dartCenterPt(252, 0);
Point powerBarStartPt(0, 0);
Point powerBarEndPt(25, 0);

// Text
Text startInstruction(startInstructionPt, "Start Power Bar : [ space ]");
Text stopInstruction(stopInstructionPt, "Stop Power Bar : [ s ]");
Text throwInstruction(throwInstructionPt, "Throw Dart         : [ t ]");
Text quitInstruction(quitInstructionPt, "Quit Game          : [ q ]");
Text gameRound(gameRoundPt, "Round: " + std::to_string(roundNum));
Text gameScore(gameScorePt, "Score: " + std::to_string(score));

// Circles
Circle firstTarget(targetCenterPt, 120); // Largest target
Circle secondTarget(targetCenterPt, 100);
Circle thirdTarget(targetCenterPt, 80);
Circle fourthTarget(targetCenterPt, 60);
Circle fifthTarget(targetCenterPt, 40);
Circle sixthTarget(targetCenterPt, 20); // Smallest target
Circle dart(dartCenterPt, 5);

// Rectangles
Rectangle powerBar(powerBarStartPt, powerBarEndPt.getX(), powerBarEndPt.getY());

void reshape_func(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);
}

void display_func(void)
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

    // Game text
  if (showInstructions)
  {
    startInstruction.setColor(1, 1, 1);
    startInstruction.draw();
    stopInstruction.setColor(1, 1, 1);
    stopInstruction.draw();
    throwInstruction.setColor(1, 1, 1);
    throwInstruction.draw();
    quitInstruction.setColor(1, 1, 1);
    quitInstruction.draw();
  }

  gameRound.setText("Round: " + std::to_string(roundNum));
  gameRound.setColor(1, 1, 1);
  gameRound.draw();
  gameScore.setText("Score: " + std::to_string(score));
  gameScore.setColor(1, 1, 1);
  gameScore.draw();

  // Targets
  firstTarget.setFillColor(0, 1, 0);
  firstTarget.draw();
  secondTarget.setFillColor(0, 0, 0);
  secondTarget.draw();
  thirdTarget.setFillColor(0, 1, 0);
  thirdTarget.draw();
  fourthTarget.setFillColor(0, 0, 0);
  fourthTarget.draw();
  fifthTarget.setFillColor(0, 1, 0);
  fifthTarget.draw();
  sixthTarget.setFillColor(0, 0, 0);
  sixthTarget.draw();

  // Dart
  dart.setCenterPt(dartCenterPt);
  dart.setFillColor(1, 0, 0);
  dart.draw();

  // Power bar
  powerBar.setHeight(powerBarEndPt.getY());
  powerBar.setFillColor(0, 0, 1);
  powerBar.draw();

  glFlush();
  glutSwapBuffers();
}

void keyboard_func(unsigned char c, int x, int y)
{
  switch (c)
  {
    // Activate power bar
    case ' ':
      if (!powerBarActive && !dartActive && !throwActive)
      {
        roundNum++;
        dartCenterPt.setY(0);
        powerBarEndPt.setY(0);
        powerBarActive = true;
      }
      break;
    // Stop power bar
    case 's':
      if (powerBarActive && !dartActive && !throwActive)
      {
        powerBarActive = false;
        dartActive = true;
      }
      break;
    // Throw dart
    case 't':
      if (!powerBarActive && dartActive && !throwActive)
      {
        powerBarSpeed += 3;
        throwActive = true;
        showInstructions = false;
      }
      break;
    // Quit
    case 'q':
      exit(0);
      break;
  }
}

void animation_func(int val)
{
  // Power bar animation
  if (powerBarActive && !dartActive && !throwActive)
  {
    if (powerBarUp)
    {
      powerBarEndPt.setY(powerBarEndPt.getY() + powerBarSpeed);
      if (powerBarEndPt.getY() >= 810)
      {
        powerBarUp = false;
      }
    }
    else
    {
      powerBarEndPt.setY(powerBarEndPt.getY() - powerBarSpeed);
      if (powerBarEndPt.getY() <= 0)
      {
        powerBarUp = true;
      }
    }
  }
  // Dart animation
  if (!powerBarActive && dartActive && throwActive == true)
  {
    if (dartCenterPt.getY() < powerBarEndPt.getY())
    {
      dartCenterPt.setY(powerBarEndPt.getY());
    }
    if (dartCenterPt.getY() == powerBarEndPt.getY())
    {
      dartActive = false;
      throwActive = false;
      update_score(dartCenterPt.getY());
    }
  }

  glutPostRedisplay();
  glutTimerFunc(ANIMATION_MSEC, animation_func, 0);
}

void update_score(float dartY)
{

  if ((dartY >= (sixthTarget.getCenterPtY() - sixthTarget.getRadius())) && (dartY <= (sixthTarget.getCenterPtY() + sixthTarget.getRadius())))
  {
    score += 6;
  }
  else if ((dartY >= (fifthTarget.getCenterPtY() - fifthTarget.getRadius())) && (dartY <= (fifthTarget.getCenterPtY() + fifthTarget.getRadius())))
  {
    score += 5;
  }
  else if ((dartY >= (fourthTarget.getCenterPtY() - fourthTarget.getRadius())) && (dartY <= (fourthTarget.getCenterPtY() + fourthTarget.getRadius())))
  {
    score += 4;
  }
  else if ((dartY >= (thirdTarget.getCenterPtY() - thirdTarget.getRadius())) && (dartY <= (thirdTarget.getCenterPtY() + thirdTarget.getRadius())))
  {
    score += 3;
  }
  else if ((dartY >= (secondTarget.getCenterPtY() - secondTarget.getRadius())) && (dartY <= (secondTarget.getCenterPtY() + secondTarget.getRadius())))
  {
    score += 2;
  }
  else if ((dartY >= (firstTarget.getCenterPtY() - firstTarget.getRadius())) && (dartY <= (firstTarget.getCenterPtY() + firstTarget.getRadius())))
  {
    score += 1;
  }
  else
  {
    score += 0;
  }
}
