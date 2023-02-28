#include "HelloGL.h"




HelloGL::HelloGL(int argc,char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// set the veiwport over the entire window
	glViewport(0, 0, 800, 800);
	// set correct perpective
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	
	glRotatef(triRotation, 1.0f, 0.0f, 0.0f);
	DrawCube();

	/*RotateRect();
	DrawRectangle();
	glEnd();

	RotateTri();
	DrawTriangle();
	glEnd();

	RotateSqu();
	DrawSquare();
	glEnd();*/

	glPopMatrix();

	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);

	glTranslatef(0.0f, 0.0f, -5.0f);
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

void HelloGL::DrawCube()
{
	glutWireCube(5);
}