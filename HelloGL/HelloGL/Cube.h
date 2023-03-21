#pragma once

#include "Structures.h"

#define OBJECTARRAY 200

class Cube
{
private:

	Mesh* _mesh;

	Vector3 _position;

	GLfloat _rotation;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();

	static bool Load(char* path);
};

