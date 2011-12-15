#include <GL/glut.h>

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


/*
	One-time initialization of OpenGL
*/
void init(void) 
{
	glClearColor(0, 0, 0, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	
	//glutGameModeString("1024x768:32@75");
	glutGameModeString("800x600:32@75");
	if(glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
	{
		glutEnterGameMode();
		init();
		glutDisplayFunc(onDisplay);
		glutMainLoop();
		return 0;
	}

	return -1;
}