#include <GL/glut.h>

#include "../include/bullseye.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(504, 896);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bullseye!");
    glutReshapeFunc(reshape_func);
    glutDisplayFunc(display_func);
    glutKeyboardFunc(keyboard_func);
    glutTimerFunc(ANIMATION_MSEC, animation_func, 0);
	glutMainLoop();

	return 0;
}
