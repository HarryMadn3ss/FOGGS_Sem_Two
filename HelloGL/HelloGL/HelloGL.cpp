#include "HelloGL.h"



HelloGL::HelloGL(int argc,char* argv[])
{
	GLUTCallbacks::init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTriangle();
	glEnd();
	glFlush(); //flushes the scene drawn to the graphics card

}

void HelloGL::DrawPolygon()
{
	
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(0.75, -0.5);
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, -0.5);
	
}

void HelloGL::DrawTriangle()
{
	
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(0, 0.5);
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);

}