#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};


class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void DrawRectangle();

	void DrawSquare();

	void DrawTriangle();

	void RotateRect();

	void RotateTri();

	void RotateSqu();

	void RotationIncrements();

	void DrawCube();


private:
	float triRotation;
	float squRotation;
	float rectRotation;

	Camera* camera;
};

