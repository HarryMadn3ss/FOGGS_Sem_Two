#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


class SceneObject;

class HelloGL;

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
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

	int vertexCount, normalCount,texCoordCount, indexCount;

	Vertex* vertices;
	Vector3* normals;
	GLushort* indices;
	TexCoord* texCoords;
	
};

struct Vector4
{
	float x, y, z, w;

	//w is for matrix multiplications
};

struct Lighting
{
	Vector4 ambient, diffuse, specular;
};

struct MaterialStruct
{
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
};

struct ListNode
{
	SceneObject* object;
	ListNode* next;
};

struct TreeNode
{
	SceneObject* object;
	ListNode* Left;
	ListNode* right;
};