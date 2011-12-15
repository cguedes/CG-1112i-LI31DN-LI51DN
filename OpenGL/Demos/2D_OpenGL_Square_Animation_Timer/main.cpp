#include <GL/glut.h>
#include <stdio.h>
#include <Windows.h>

int getMillisecs() 
{
	return timeGetTime();
}

float fps = 100;
float getFpsMilisecs() { return 1000.0 / fps; }



/* Definition of a Square type */
struct Square 
{
	float x;
	float y;
	float angle;
	
	float deltaTranslation;
	float rotationSpeedPerSeconds;

	Square() 
	{
		x = y = .25; 
		angle = 10;

		deltaTranslation = .05;
		rotationSpeedPerSeconds = 360;	// rotation speed per seconds
	}
};
Square square;


void moveBySpecialKey(int key);
void drawFpsAndRotation();

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
	glRotatef(square.angle, 0, 0, 1);

	glColor3f(1, 0, 0);				// Current color is RED
	glBegin(GL_POLYGON);			// Draw a polygon with 4 vertexes
		glVertex2f(square.x + .00, square.y + .00);
		glVertex2f(square.x + .50, square.y + .00);
		glVertex2f(square.x + .50, square.y + .50);
		glVertex2f(square.x + .00, square.y + .50);
	glEnd();

	drawFpsAndRotation();

	glutSwapBuffers();				// Swap double-buffering buffers
}

// WARNING: ONLY WORKS WITH THIS SAMPLE
void drawFpsAndRotation() 
{
	// write 2D text	
	glPushMatrix();

	glLoadIdentity();
	glColor3f(1, 1, 1);
	
	// FPS
	glRasterPos2f(0.4, .85);
    static char txtFPS[20];
	sprintf_s(txtFPS, "FPS: %d", (int)fps);
	for (const char *c = txtFPS; *c != '\0'; c++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
    }

	// ROTATION
	glRasterPos2f(0.4, .75);
    static char txtRot[20];
	sprintf_s(txtRot, "ROT: %d", (int)square.rotationSpeedPerSeconds);
	for (const char *c = txtRot; *c != '\0'; c++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
    }

	glPopMatrix();
}


void onSpecialKey(int key, int _, int __)
{
	moveBySpecialKey(key);
	glutPostRedisplay();
}

void onKeyboardKey(unsigned char key, int _, int __)
{
	key = tolower(key);
	switch(key)
	{
		case 'q':
			fps += 1;
			break;
		case 'a':
			fps -= 1;
			break;

		case 'w':
			square.rotationSpeedPerSeconds += 5;
			break;
		case 's':
			square.rotationSpeedPerSeconds -= 5;
			break;
	}

	glutPostRedisplay();
}

void onTimer(int lastMillisecs)
{
	int currentMillisecs = getMillisecs();
	int deltaMullisecs = currentMillisecs - lastMillisecs;
	float seconds = deltaMullisecs / 1000.0;

	square.angle += square.rotationSpeedPerSeconds * seconds;

	glutTimerFunc(getFpsMilisecs(), onTimer, currentMillisecs);	// set animation callback to execute at fps rate
	glutPostRedisplay();
}


void moveBySpecialKey(int key)
{
	float dx = 0, dy = 0;
	switch(key)
	{
		case GLUT_KEY_LEFT:		dx = -square.deltaTranslation; break;
		case GLUT_KEY_RIGHT:	dx = +square.deltaTranslation; break;
		case GLUT_KEY_UP:		dy = +square.deltaTranslation; break;
		case GLUT_KEY_DOWN:		dy = -square.deltaTranslation; break;
	}

	square.x += dx;
	square.y += dy;
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("OpenGL Square");

    init();							// initialize application (openGL)
    glutDisplayFunc(onDisplay);		// set display callback function
	glutSpecialFunc(onSpecialKey);	// set key up callback function (for special keys LEFT, ...)
	glutKeyboardFunc(onKeyboardKey);
	
	glutTimerFunc(getFpsMilisecs(), onTimer, getMillisecs());	// set animation callback to execute at fps rate

	// HELP (minimalist)
	printf("================================================================\n");
	printf("HELP\n");
	printf("----------------------------------------------------------------\n");
	printf("  Q: increase frame-rate\n");
	printf("  A: decrease frame-rate\n");
	printf("\n");
	printf("  W: increase rotation speed\n");
	printf("  S: decrease rotation speed\n");
	printf("\n");
	printf("  LEFT:  move square position to the left\n");
	printf("  RIGHT: move square position to the right\n");
	printf("  UP:    move square position to the up\n");
	printf("  DOWN:  move square position to the down\n");
	printf("================================================================\n");


	glutMainLoop();					// application loop

	return 0;
}