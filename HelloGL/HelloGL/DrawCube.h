#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"



struct Color
	{
		GLfloat r, g, b;
	};
	struct Vertex
	{
		GLfloat x, y, z;
	};


class DrawCube
{
public:

	DrawCube();
	~DrawCube();

	DrawCube* cube;

	void DrawCubeArray();

private:

	

	static Vertex vertices[];
	static Color colors[];

	


};

