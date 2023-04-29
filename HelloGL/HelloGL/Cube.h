#pragma once

#include "Structures.h"
#include "SceneObject.h"



class Cube : public SceneObject
{
private:	

	Vector3 _position;

	GLfloat _rotation;

	Material* _material;

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	void DefineMaterial();
		
};

