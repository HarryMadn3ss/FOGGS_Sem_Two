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
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);		
	DrawBatmanTriangles();
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


void HelloGL::DrawBatmanTriangles()
{
	glBegin(GL_TRIANGLES);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.5f);
	glVertex2f(-0.3f, 0.2f);
	glVertex2f(-0.2f, 0.2f);
	

	glBegin(GL_TRIANGLES);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(0.3f, 0.5f);
	glVertex2f(0.3f, 0.2f);
	glVertex2f(0.2f, 0.2f);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.3f, 0.2f);
	glVertex2f(0.3f, 0.2f);
	glVertex2f(-0.3f, -0.5f);

	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2f(0.2f, 0.1f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.2f, -0.05f);
	
	
	

		
	
}

void HelloGL::DrawBatmanPolygons()
{
	
}