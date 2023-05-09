#pragma once
#include "Structures.h"
#include "Texture2D.h"
#include "Materials.h"

#define OBJECTARRAY 200

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;


private:


public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

