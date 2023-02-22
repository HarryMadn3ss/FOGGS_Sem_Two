#include "HelloGL.h"
#define REFRESHRATE 16



HelloGL::HelloGL(int argc,char* argv[])
{
	//variable constructs
	triRotation = 0.0f;
	squRotation = 0.0f;
	rectRotation = 0.0f;


	//
	GLUTCallbacks::init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	
	RotateRect();
	DrawRectangle();
	glEnd();

	RotateTri();
	DrawTriangle();
	glEnd();

	RotateSqu();
	DrawSquare();
	glEnd();

	glPopMatrix();

	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	RotationIncrements();
	glutPostRedisplay(); //forces the scene to refresh after the update is finished
		
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		squRotation += 0.5f;
	}
	if (key == 'a')
	{
		squRotation -= 0.5f;
	}
}

void HelloGL::DrawRectangle()
{
	
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	/*glColor4f(0.0f, 0.0f, 1.0f, 0.0f);*/
	glVertex2f(0.75, -0.5);
	/*glColor4f(0.0f, 1.0f, 0.0f, 0.0f);*/
	glVertex2f(-0.75, -0.5);
	
}

void HelloGL::DrawTriangle()
{
	
	glBegin(GL_TRIANGLES);
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(0, 0.5);
	/*glColor4f(0.0f, 1.0f, 0.0f, 0.0f);*/
	glVertex2f(0.5f, 0.0f);
	/*glColor4f(0.0f, 0.0f, 1.0f, 0.0f);*/
	glVertex2f(-0.5f, 0.0f);

}

void HelloGL::DrawSquare()
{
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, 0.75);
	glVertex2f(0.75, 0.75);
	/*glColor4f(0.0f, 0.0f, 1.0f, 0.0f);*/
	glVertex2f(0.75, -0.75);
	/*glColor4f(0.0f, 1.0f, 0.0f, 0.0f);*/
	glVertex2f(-0.75, -0.75);
}

void HelloGL::RotationIncrements()
{
	triRotation += 0.5f;

	if (triRotation >= 360.0f)
	{
		triRotation = 0.0f;
	}

	squRotation += 0.5f;

	if (squRotation >= 360.0f)
	{
		squRotation = 0.0f;
	}

	rectRotation += 0.5f;

	if (rectRotation >= 360.0f)
	{
		rectRotation = 0.0f;
	}
}

void HelloGL::RotateRect()
{
	glRotatef(rectRotation, 0.0f, 0.0f, -1.0f);
}

void HelloGL::RotateTri()
{
	glRotatef(triRotation, 0.0f, 1.0f, 0.0f);
}

void HelloGL::RotateSqu()
{
	glRotatef(squRotation, 1.0f, 0.0f, 0.0f);
}