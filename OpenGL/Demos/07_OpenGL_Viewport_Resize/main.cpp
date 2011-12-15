#include <GL/glut.h>
#include <stdio.h>

void drawSquare(float x, float y, float size, float r, float g, float b)
{
	glPushMatrix();
	
	glColor3f(r, g, b);
	glTranslatef(x, y, 0);

	glBegin(GL_POLYGON);			
		glVertex2f(0, 0);
		glVertex2f(size, 0);
		glVertex2f(size, size);
		glVertex2f(0, size);
	glEnd();

	glPopMatrix();
}

/*
	Display routine.
*/
void onDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clear openGL color buffer

	drawSquare(.25, .25, .5, 1, 0, 0);
	drawSquare(1.25, .25, .5, 1, 1, 0);

	// Draw axis
	//  -> XX Axis
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(.5, 0);
	glEnd();
	//  -> YY Axis
	glColor3f(0,1,0);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, .5);
	glEnd();
	//  -> Origin
	glColor3f(1,1,1);
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2f(0, 0);
	glEnd();

	

	glFlush();						// Flush current buffer
}

void onReshape(int width, int height)
{
	// Set the area of the window that should be considered 
	glViewport(0, 0, width, height);

	// change the current projection to match the same aspect ratio of the window
	glMatrixMode(GL_PROJECTION);
	double factor = width / (double)height;
	glLoadIdentity();							// clear current matrix content
	glOrtho(-factor, factor, -1, 1, -1, 1);		// set the ortographic projection with a 2 x 2 size when the aspect ratio is 1:1
	
	// change back to the model-view matrix
	glMatrixMode(GL_MODELVIEW);
}

void onKeyboard(unsigned char key, int _, int __)
{
	if(key == 'x') exit(0);

	if(key >= '1' && key <= '9')
	{
		int factor = key - '0';
		int height = 250;
		int width = height * factor;
		// programatically change the window size
		glutReshapeWindow(width, height);
	}

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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("OpenGL Square");

    init();							// initialize application (openGL)
    glutDisplayFunc(onDisplay);		// set display callback function
	glutReshapeFunc(onReshape);
	glutKeyboardFunc(onKeyboard);

	// HELP (minimalist)
	printf("================================================================\n");
	printf("HELP\n");
	printf("----------------------------------------------------------------\n");
	printf("  1-9: change the window aspect-ratio (Width:Height) \n");
	printf("   1 -> 1:1 aspect-ratio \n");
	printf("   2 -> 2:1 aspect-ratio \n");
	printf("   3 -> 3:1 aspect-ratio \n");
	printf("   ... \n");
	printf("\n");
	printf("  x: exits the application\n");
	printf("================================================================\n");

	glutMainLoop();					// application loop

	return 0;
}