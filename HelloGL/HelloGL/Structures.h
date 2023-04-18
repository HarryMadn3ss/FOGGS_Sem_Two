#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


class HelloGL;

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	int vertexCount, colorCount,texCoordCount, indexCount;

	Vertex* vertices;
	Color* colors;
	GLushort* indices;
	TexCoord* texCoords;
	
};