#pragma once

#include <ctime>
#include <cstdlib>


#include "MeshLoader.h"
#include "GLUTCallbacks.h"

#include "Cube.h"
#include "StaticObject.h"
#include "LinkedList.h"
#include "Materials.h"
#include "Lighting.h"

#define REFRESHRATE 16


class HelloGL
{
protected:

private:
	float triRotation;
	float squRotation;
	float rectRotation;

	Camera* camera;
		
	//SceneObject* objects[OBJECTARRAY];

	LinkedList* _objectList;
	ListNode* _objectHead;

	//lighting
	Vector4* _lightPosition;
	LightingStruct* _lightData;
	bool _lightOn;

	
	int _materialNum;

public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);
	
	void InitObjects();

	void InitGL(int argc, char* argv[]);

	void InitLighting();


};

