#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"


class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void DrawRectangle();

	void DrawSquare();

	void DrawTriangle();

	void RotateRect();

	void RotateTri();

	void RotateSqu();

	void RotationIncrements();



private:
	float triRotation;
	float squRotation;
	float rectRotation;
};

