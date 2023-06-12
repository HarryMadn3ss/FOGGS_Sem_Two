#pragma once

#include <ctime>
#include <cstdlib>


#include "MeshLoader.h"
#include "GLUTCallbacks.h"

#include "DynamicObject.h"
#include "StaticObject.h"
#include "LinkedList.h"
#include "Materials.h"
#include "Lighting.h"
#include "TextRenderer.h"
#include "SceneGraphNode.h"

#define REFRESHRATE 16


class HelloGL
{
protected:

private:	

	Camera* camera;
	
	LinkedList* _objectList;
	ListNode* _objectHead;
	SceneGraphNode* _sceneGraphRoot;

	//lighting
	Vector4* _lightPosition;
	LightingStruct* _lightData;
	bool _lightOn;

	//text location
	Vector3* _textPosition;
	Color* _textColor;

	
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

