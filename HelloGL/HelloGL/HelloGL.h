#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"


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
		
	Cube* cube[OBJECTARRAY];


public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);
	



};

