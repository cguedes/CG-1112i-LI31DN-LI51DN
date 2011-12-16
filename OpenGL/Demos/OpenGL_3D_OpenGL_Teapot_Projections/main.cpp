#include <GL/glut.h>
#include <Windows.h>

float fps = 100;
int getMillisecs() { return timeGetTime(); }
float getFpsMilisecs() { return 1000.0 / fps; }

float angle = 0;
float rotationPerSecond = 90;

bool isOrtho = true, projectionChanged = true;
int width, height;

void drawAxis();

void onDisplay(void)
{
	if(projectionChanged)
	{
		// change the current projection to match the same aspect ratio of the window
		glMatrixMode(GL_PROJECTION);
		double factor = width / (double)height;

		glLoadIdentity();							// clear current matrix content

		if(isOrtho) 
		{
			glOrtho(-factor*2, factor*2, -2, 2, -5, 5);		// set the ortographic projection with a 4 x 4 size when the aspect ratio is 1:1
		}
		else
		{
			gluPerspective(60, factor, .1, 10);				// fovy = 60 with an aspect ratio of 1:1 and near = .1 and far = 10
		}
		projectionChanged = false;
	}
	
	// change back to the model-view matrix
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// clear openGL color buffer & depth

	// Setup camera
	glLoadIdentity();
	gluLookAt(2, 2, 2,
			  0,  0, 0,
			  0,  1, 0);

	// Draw teapot
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle, 0, 0, 1);
	glutSolidTeapot(1);
	//glutSolidCube(1);
	glPopMatrix();

	drawAxis();

	glutSwapBuffers();
}

void drawAxis() {
	glPushMatrix();

	glDisable(GL_LIGHTING);

	float axisSize = 2;

	// Draw axis
	//  -> XX Axis
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(axisSize, 0);
	glEnd();
	//  -> YY Axis
	glColor3f(0,1,0);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, axisSize);
	glEnd();
	//  -> ZZ Axis
	glColor3f(0,0,1);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, axisSize);
	glEnd();
	//  -> Origin
	glColor3f(1,1,1);
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2f(0, 0);
	glEnd();

	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void onReshape(int w, int h)
{
	// Set the area of the window that should be considered 
	glViewport(0, 0, w, h);

	width = w;
	height = h;
}

void onTimer(int lastMillisecs)
{
	int currentMillisecs = getMillisecs();
	int deltaMullisecs = currentMillisecs - lastMillisecs;
	float seconds = deltaMullisecs / 1000.0;

	angle += rotationPerSecond * seconds;

	glutTimerFunc(getFpsMilisecs(), onTimer, currentMillisecs);	// set animation callback to execute at fps rate
	glutPostRedisplay();
}

void onKeyboardUp(unsigned char key, int _, int __)
{
	if(key == 'o') { isOrtho = true; projectionChanged = true; }
	else if(key == 'p') { isOrtho = false; projectionChanged = true; }

	glutPostRedisplay();
}


/*
	One-time initialization of OpenGL
*/
void init(void) 
{
	glClearColor(0, 0, 0, 0);		// set background color

	/* enable depth testing */
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH /* depth buffer */);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL 3D");

    init();							// initialize application (openGL)
    glutDisplayFunc(onDisplay);		// set display callback function
	glutReshapeFunc(onReshape);
	glutKeyboardUpFunc(onKeyboardUp);
	glutTimerFunc(getFpsMilisecs(), onTimer, getMillisecs());	// set animation callback to execute at fps rate


	glutMainLoop();					// application loop

	return 0;
}