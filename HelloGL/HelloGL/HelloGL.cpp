#include "HelloGL.h"

Vertex HelloGL::vertices[] = { 1, 1, 1,	-1, 1, 1,	-1, -1, 1, //v0-v1-v1 (front)
							-1, -1, 1,	1, -1, 1,	1, 1, 1, //v2-v3-v0

								1, 1, 1,	1, -1, 1,	1, -1, -1, //v0-v3-v4 (right)
								1, -1, -1,	1, 1, -1,	1, 1, 1, //v4-v5-v0

								1, 1, 1,	1, 1, -1, -1, 1, -1, //v0-v5-v6 (top)
								-1, 1, -1,	-1, 1, 1,	1, 1, 1, //v6-v1-v0

								-1, 1, 1,	-1, 1, -1,	-1, -1, -1, //v1-v6-v7 (left)
								-1, -1, -1,	-1, -1, 1,	-1, 1, 1, //v7-v2-v1

								-1, -1, -1,	1, -1, -1,	1, -1, 1, //v7-v4-v3 (bottom)
								1, -1, 1,	-1, -1, 1,	-1, -1, -1, //v3-v2-v7

								1, -1, -1,	-1, -1, -1,	-1, 1, -1, //v4-v7-v3 (back)
								-1, 1, -1, 1, 1, -1,	1, -1, -1 }; //v6-v5-v4

Color HelloGL::colors[] = { 1, 1, 1,	1, 1, 0,	1, 0, 0,
							1, 0, 0,	1, 0, 1,	1, 1, 1,

							1, 1, 1,	1, 0, 1,	0, 0, 1,
							0, 0 , 1,	0, 1, 1,	1, 1, 1,

							1, 1, 1,	0, 1, 1,	0, 1, 0,
							0, 1, 0,	1, 1, 0,	1, 1, 1,

							1, 1, 0,	0, 1, 1,	0, 1, 0,
							0, 0, 0,	1, 0, 0,	1, 1, 0,

							0, 0, 0,	0, 0 , 1,	1, 0, 1,
							1, 0, 1,	1, 0, 0,	0, 0, 0,

							0, 0, 1,	0, 0, 0,	0, 1, 0,
							0, 1, 0,	0, 1, 1,	0, 0, 1 };



//indexed
Vertex HelloGL::indexedVertices[] = {1, 1, 1,	-1, 1, 1, //v0-v1
									-1, -1, 1,	1, -1, 1, //v2-v3
									1, -1, -1,	1, 1, -1, //v4-v5
									-1, 1, -1,	-1, -1, -1};

Color HelloGL::indexedColors[] = {1, 1, 1,	1, 1, 0,
								1, 0, 0,	1, 0, 1,
								0, 0, 1,	0, 1, 1,
								0, 1, 0,	0, 0, 0};

GLushort HelloGL::indices[] = { 0, 1, 2,	2, 3, 0,	//front
								0, 3, 4,	4, 5, 0,	//right
								0, 5, 6,	6, 1, 0,	//top
								1, 6, 7,	7, 2, 1,	//left
								7, 4, 3,	3, 2, 7,	//bottom
								4, 7, 6,	6, 5, 4};	//back


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
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
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


	/*glBegin(GL_TRIANGLES);

	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}*/

	DrawIndexedCube();
	
	glEnd();
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
		//squRotation += 0.5f;
		camera->eye.x += 0.1f;
		camera->center.x += 0.1f;
	}
	if (key == 'a')
	{
		//squRotation -= 0.5f;
		camera->eye.x -= 0.1f;
		camera->center.x -= 0.1f;
	}
	if (key == 'w')
	{
		camera->eye.z -= 0.1f;
		camera->center.z -= 0.1f;
	}
	if (key == 's')
	{
		camera->eye.z += 0.1f;
		camera->center.z += 0.1f;
	}
	if (key == ' ')
	{
		camera->eye.y += 0.1f;
		camera->center.y += 0.1f;
	}
	if (key == 'c')
	{
		camera->eye.y -= 0.1f;
		camera->center.y -= 0.1f;
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
	//glutWireCube(5);

	glBegin(GL_TRIANGLES);

	//face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	//face v4-v5,v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	//face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();

}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}

	glEnd();

	glPopMatrix();

}