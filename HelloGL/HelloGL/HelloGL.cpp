#include "HelloGL.h"


HelloGL::HelloGL(int argc,char* argv[])
{
	srand(time(0));

	InitGL(argc, argv);
	
	InitObjects();

	InitLighting();
	
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
		
	_objectList->DeleteList(&_objectHead);	
	

	delete _objectList;
	_objectList = nullptr;

	delete _objectHead;
	_objectHead = nullptr;

	delete _lightData;
	_lightData = nullptr;

	delete _lightPosition;
	_lightPosition = nullptr;	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	_objectList->DrawNode(_objectHead);
		
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
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//material switcher
	
	_materialNum = 1;

	//linked list
	_objectList = new LinkedList();
	_objectHead = nullptr;

	for (int i = 0; i < (OBJECTARRAY); i++)
	{
		_objectList->MakeNode(&_objectHead, new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
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
	//window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	//refreshrate
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	//keyboard
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// set the veiwport over the entire window
	glViewport(0, 0, 800, 800);
	// set correct perpective
	gluPerspective(80, 1, 1, 1000);
	//lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//stop drawing
	glMatrixMode(GL_MODELVIEW);
	//enable culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//depth test
	glEnable(GL_DEPTH_TEST);
}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->ambient.x = 0.2;
	_lightData->ambient.y = 0.2;
	_lightData->ambient.z = 0.2;
	_lightData->ambient.w = 1.0;
	_lightData->diffuse.x = 0.8;
	_lightData->diffuse.y = 0.8;
	_lightData->diffuse.z = 0.8;
	_lightData->diffuse.w = 1.0;
	_lightData->specular.x = 0.2;
	_lightData->specular.y = 0.2;
	_lightData->specular.z = 0.2;
	_lightData->specular.w = 1.0;

}

void HelloGL::Update()
{
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	
	glTranslatef(0.0f, 0.0f, -5.0f);
		
	
	_objectList->UpdateNode(_objectHead);
	
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
	if (key == 'p')
	{
		if (_materialNum == 0)
		{
			Materials::Instance()->DefineMaterial(STANDARD);
			_materialNum++;
		}
		else if (_materialNum == 1)
		{
			Materials::Instance()->DefineMaterial(RED);
			_materialNum++;
		}
		else if (_materialNum == 2)
		{
			Materials::Instance()->DefineMaterial(BLUE);
			_materialNum++;
		}
		else if (_materialNum == 3)
		{
			Materials::Instance()->DefineMaterial(GREEN);
			_materialNum = 0;
		}
		
	}
}

