#pragma once
#include "Structures.h"
#include "Texture2D.h"
#include "Materials.h"

#define OBJECTARRAY 50

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

	//OBJLoaderVertices* _mesh;

private:


public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	//SceneObject(OBJLoaderVertices* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

