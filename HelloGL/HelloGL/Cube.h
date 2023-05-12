#pragma once

#include "Structures.h"
#include "SceneObject.h"
#include "OBJLoader.h"


class Cube : public SceneObject
{
private:	

	Vector3 _position;
	Vector3 _scale;

	GLfloat _rotation;

	

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	Cube(Mesh* mesh, Texture2D* texture, Vector3 position, Vector3 scale);
	
	~Cube();

	void Draw();
	void Update();
	
	MaterialStruct* _material;

};

