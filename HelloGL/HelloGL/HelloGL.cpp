#include "HelloGL.h"

//Vertex HelloGL::vertices[] = { 1, 1, 1,	-1, 1, 1,	-1, -1, 1, //v0-v1-v1 (front)
//							-1, -1, 1,	1, -1, 1,	1, 1, 1, //v2-v3-v0
//
//								1, 1, 1,	1, -1, 1,	1, -1, -1, //v0-v3-v4 (right)
//								1, -1, -1,	1, 1, -1,	1, 1, 1, //v4-v5-v0
//
//								1, 1, 1,	1, 1, -1, -1, 1, -1, //v0-v5-v6 (top)
//								-1, 1, -1,	-1, 1, 1,	1, 1, 1, //v6-v1-v0
//
//								-1, 1, 1,	-1, 1, -1,	-1, -1, -1, //v1-v6-v7 (left)
//								-1, -1, -1,	-1, -1, 1,	-1, 1, 1, //v7-v2-v1
//
//								-1, -1, -1,	1, -1, -1,	1, -1, 1, //v7-v4-v3 (bottom)
//								1, -1, 1,	-1, -1, 1,	-1, -1, -1, //v3-v2-v7
//
//								1, -1, -1,	-1, -1, -1,	-1, 1, -1, //v4-v7-v3 (back)
//								-1, 1, -1, 1, 1, -1,	1, -1, -1 }; //v6-v5-v4
//
//Color HelloGL::colors[] = { 1, 1, 1,	1, 1, 0,	1, 0, 0,
//							1, 0, 0,	1, 0, 1,	1, 1, 1,
//
//							1, 1, 1,	1, 0, 1,	0, 0, 1,
//							0, 0 , 1,	0, 1, 1,	1, 1, 1,
//
//							1, 1, 1,	0, 1, 1,	0, 1, 0,
//							0, 1, 0,	1, 1, 0,	1, 1, 1,
//
//							1, 1, 0,	0, 1, 1,	0, 1, 0,
//							0, 0, 0,	1, 0, 0,	1, 1, 0,
//
//							0, 0, 0,	0, 0 , 1,	1, 0, 1,
//							1, 0, 1,	1, 0, 0,	0, 0, 0,
//
//							0, 0, 1,	0, 0, 0,	0, 1, 0,
//							0, 1, 0,	0, 1, 1,	0, 0, 1 };



//indexed



HelloGL::HelloGL(int argc,char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;


	for (int i = 0; i < OBJECTARRAY; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	
	

	//variable constructs
	triRotation = 0.0f;
	squRotation = 0.0f;
	rectRotation = 0.0f;


	//
	GLUTCallbacks::init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
	gluPerspective(80, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;

	for (int i = 0; i < OBJECTARRAY; i++)
	{
		delete cube[i];
	}
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	Cube::Load((char*)"txtFiles/cube.txt");

	for (int i = 0; i < OBJECTARRAY; i++)
	{
		cube[i]->Draw();
	}
	
		
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

	for (int i = 0; i < OBJECTARRAY; i++)
	{
		cube[i]->Update();
	}
	
	
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

