#include <GL/glut.h>
#include <stdio.h>

static const float fpsMilisecs = 1000.0 / 400;

/* 
	Square model
*/
float x = .25, y = .25;
float angle = 0;

void moveBySpecialKey(int key);

/*
	Display routine.
*/
void onDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clear openGL color buffer

	// Setup camera
	glLoadIdentity();
	gluLookAt(0, 0, 1,
			  0,  0, 0,
			  0,  1, 0);

	// Draw teapot
	glColor3f(1,1,0);
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	glutSolidTeapot(.5);

	glutSwapBuffers();				// Swap double-buffering buffers
}

void onSpecialKey(int key, int _, int __)
{
	moveBySpecialKey(key);
	glutPostRedisplay();
}

void onTimer(int data)
{
	static const float DELTA_ANGLE = 1;
	angle += DELTA_ANGLE;

	// re-schedule timer 
	glutTimerFunc(fpsMilisecs, onTimer, 0);	// set animation callback to execute at 25fps rate

	glutPostRedisplay();
}


void moveBySpecialKey(int key)
{
	static const float DELTA = .05;
	float dx = 0, dy = 0;
	switch(key)
	{
		case GLUT_KEY_LEFT:		dx = -DELTA; break;
		case GLUT_KEY_RIGHT:	dx = +DELTA; break;
		case GLUT_KEY_UP:		dy = +DELTA; break;
		case GLUT_KEY_DOWN:		dy = -DELTA; break;
	}

	x += dx;
	y += dy;
}

/*
	One-time initialization of OpenGL
*/
void init(void) 
{
	glClearColor(0, 0, 0, 0);		// set background color

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

/*  
    Declare initial window size, position, and display mode (single buffer and RGBA). 
    Open window with “Hello GLUT“ in its title bar. 
    Call initialization routines. 
    Register callback function to display graphics. 
    Enter main loop and process events. 
*/
int main(int argc, char** argv)
{
    printf("hello OpenGL");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Square");

    init();							// initialize application (openGL)
    glutDisplayFunc(onDisplay);		// set display callback function
	glutSpecialFunc(onSpecialKey);	// set key up callback function (for special keys LEFT, ...)
	
	glutTimerFunc(fpsMilisecs, onTimer, 0);	// set animation callback to execute at 25fps rate

	glutMainLoop();					// application loop

	return 0;
}