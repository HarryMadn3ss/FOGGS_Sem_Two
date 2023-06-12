#include "HelloGL.h"
#include "tgaLoader.h"

HelloGL::HelloGL(int argc,char* argv[])
{
	srand(time(NULL));

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

	delete _textPosition;
	_textPosition = nullptr;

	delete _textColor;
	_textColor = nullptr;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	_objectList->DrawNode(_objectHead);
	_sceneGraphRoot->Draw();
	TextRenderer::Instance()->DrawString("HelloGL", _textPosition, _textColor);
		
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;


	// Load models
	Mesh* rombusMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/Rombus.obj");
	Mesh* cubeMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/cube.obj");
	Mesh* pyramidMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/pyramid.obj");
	Mesh* monkeyMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/Monke.obj");
	Mesh* ballMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/Sphere.obj");
	Mesh* saturnMesh = OBJLoader::Instance()->LoadOBJToMesh("files/OBJFiles/Saturn.obj");


	// Load textures
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"files/textures/Penguins.raw", 512, 512);

	TGALoader* tgaLoader = new TGALoader();
	Texture2D* earthTGA = tgaLoader->LoadTextureTGA("files/textures/Earth_TEXTURE_CM.tga");

	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//material switcher
	_materialNum = 1;

	//light switch
	_lightOn = true;

	//text
	_textPosition = new Vector3;
	_textColor = new Color;	
	_textPosition->x = -1.4f; _textPosition->y = -1.0f; _textPosition->z = -1.0f;
	_textColor->r = 1.0f; _textColor->g = 0.0f; _textColor->b = 1.0f;

	// Setup linked list
	_objectList = new LinkedList();
	_objectHead = nullptr;

	for (int i = 0; i < (OBJECTARRAY / 6); i++)
	{
		_objectList->MakeNode(&_objectHead, new DynamicObject(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
		_objectList->MakeNode(&_objectHead, new DynamicObject(pyramidMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
		_objectList->MakeNode(&_objectHead, new DynamicObject(rombusMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
		_objectList->MakeNode(&_objectHead, new DynamicObject(monkeyMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
		_objectList->MakeNode(&_objectHead, new DynamicObject(ballMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
		_objectList->MakeNode(&_objectHead, new DynamicObject(saturnMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -((rand() % 1000) / 10.0f)));
	}
	

	// Setup SceneGraph
	_sceneGraphRoot = new SceneGraphNode(new DynamicObject(ballMesh, earthTGA, Vector3{ 0, 0, -10 }, Vector3{ 1, 1, 1 }));
	_sceneGraphRoot->AddChild(new SceneGraphNode(new DynamicObject(ballMesh, earthTGA, 5, 0, 0)));
	SceneGraphNode* parentPlanet = _sceneGraphRoot->AddChild(new SceneGraphNode(new DynamicObject(ballMesh, earthTGA, Vector3{ 10, 0, 0 }, Vector3{ 0.5f, 0.5f, 0.5f })));
	parentPlanet->AddChild(new SceneGraphNode(new DynamicObject(ballMesh, earthTGA, Vector3{ 7, 0, 0 }, Vector3{ 0.5f, 0.5f, 0.5f })));

	
	
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
	_lightData = Lighting::Instance()->SetLighting(_lightOn);
	_lightPosition = Lighting::Instance()->SetLightingPosition();
}

void HelloGL::Update()
{

	_lightData = Lighting::Instance()->GetLighting();
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	
	_objectList->UpdateNode(_objectHead);
	_sceneGraphRoot->Update(0);
	
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
	if (key == 'l')
	{
		if (_lightOn)
		{
			_lightOn = false;
			Lighting::Instance()->SetLighting(_lightOn);
		}
		else
		{
			_lightOn = true;
			Lighting::Instance()->SetLighting(_lightOn);
		}
	}
}

