#pragma once

#include "Structures.h"
#include "SceneObject.h"
#include "OBJLoader.h"


class Cube : public SceneObject
{
private:	

	Vector3 _position;

	GLfloat _rotation;

	

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	
	MaterialStruct* _material;

};

