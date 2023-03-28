#pragma once

#include "Structures.h"
#include "SceneObject.h"

#define OBJECTARRAY 200

class Cube : public SceneObject
{
private:	

	Vector3 _position;

	GLfloat _rotation;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
		
};

