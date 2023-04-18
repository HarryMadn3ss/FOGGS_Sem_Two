#include "HelloGL.h"



HelloGL::HelloGL(int argc,char* argv[])
{
	srand(time(0));

	InitGL(argc, argv);
	
	InitObjects();		
	
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;

	for (int i = 0; i < OBJECTARRAY; i++)
	{
		delete objects[i];
	}
	
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	

	for (int i = 0; i < OBJECTARRAY; i++)
	{
		objects[i]->Draw();
	}
	
		
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load((char*)"files/txtFiles/cube.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"files/textures/Penguins.raw", 512, 512);

	Mesh* staticMesh = MeshLoader::Load((char*)"files/txtFiles/pyramid.txt");

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	for (int i = 0; i < (OBJECTARRAY / 2); i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f));
	}
	for (int i = (OBJECTARRAY / 2); i < OBJECTARRAY; i++)
	{
		objects[i] = new StaticObject(staticMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f));
	}

	//variable constructs
	triRotation = 0.0f;
	squRotation = 0.0f;
	rectRotation = 0.0f;
}

void HelloGL::InitGL(int argc, char* argv[])
{
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
		objects[i]->Update();
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

