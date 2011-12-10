#include <windows.h>
#include <gl\GL.h>
#include <gl\glut.h>
#include <stdio.h>

static const float fpsMilisecs = 1000.0 / 360;

/* 
	Square model
*/
float x = .25, y = .25;
float angle = 10;

void moveBySpecialKey(int key);

/*
	Display routine.
*/
void onDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clear openGL color buffer
	
	// Draw white center point
	glColor3f(1, 1, 1);
	glPointSize(2);
	glBegin(GL_POINTS);
		glVertex2f(0, 0);
	glEnd();

	// Draw Square
	glLoadIdentity();
	glRotatef(angle, 0, 0, 1);

	glColor3f(1, 0, 0);				// Current color is RED
	glBegin(GL_POLYGON);			// Draw a polygon with 4 vertexes
		glVertex2f(x + .00, y + .00);
		glVertex2f(x + .50, y + .00);
		glVertex2f(x + .50, y + .50);
		glVertex2f(x + .00, y + .50);
	glEnd();


	glutSwapBuffers();				// Swap double-buffering buffers
}

void onSpecialKey(int key, int _, int __)
{
	moveBySpecialKey(key);
	glutPostRedisplay();
}

void onTimer(int _)
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