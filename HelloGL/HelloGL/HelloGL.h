#pragma once

#include <ctime>
#include <cstdlib>


#include "MeshLoader.h"
#include "GLUTCallbacks.h"

#include "Cube.h"
#include "StaticObject.h"

#define REFRESHRATE 16


class HelloGL
{
private:
	float triRotation;
	float squRotation;
	float rectRotation;

	/*static Vertex vertices[];
	static Color colors[];

	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];*/

	Camera* camera;
		
	SceneObject* objects[OBJECTARRAY];


public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);
	
	void InitObjects();

	void InitGL(int argc, char* argv[]);


};

