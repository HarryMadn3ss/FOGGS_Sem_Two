#pragma once
#include "SceneObject.h"
#include "Structures.h"

class StaticObject : public SceneObject
{
protected:
	Vector3 _position;

private:

	

public:
	StaticObject(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~StaticObject();

	void Draw();
	void Update();	

};

