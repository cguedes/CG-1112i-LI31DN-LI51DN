#include <windows.h>
#include <gl\GL.h>
#include <gl\glut.h>
#include <stdio.h>

/*
	Display routine.
*/
void onDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clear openGL color buffer
	glColor3f(1, 0, 0);				// Current color is RED
	glBegin(GL_POLYGON);			// Draw a polygon with 4 vertexes
		glVertex2f(.25, .25);
		glVertex2f(.75, .25);
		glVertex2f(.75, .75);
		glVertex2f(.25, .75);
	glEnd();
	glFlush();						// Flush current buffer
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Square");

    init();							// initialize application (openGL)
    glutDisplayFunc(onDisplay);		// set display callback function

	glutMainLoop();					// application loop

	return 0;
}