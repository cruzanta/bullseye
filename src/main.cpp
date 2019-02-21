#include <GL/glut.h>

#include "bullseye.cpp"

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(504, 896);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Bullseye");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(getKeyboardInput);
  glutTimerFunc(ANIMATION_MSEC, animate, 0);
  glutMainLoop();

  return 0;
}
